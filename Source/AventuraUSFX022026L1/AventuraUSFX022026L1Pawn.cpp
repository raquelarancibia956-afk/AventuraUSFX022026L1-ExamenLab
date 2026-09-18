// Copyright Epic Games, Inc. All Rights Reserved.

#include "AventuraUSFX022026L1Pawn.h"
#include "AventuraUSFX022026L1Projectile.h"
#include "PlataformaIndestructible.h"   // NUEVO
#include "PlataformaDestructible.h"     // NUEVO
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName AAventuraUSFX022026L1Pawn::MoveForwardBinding("MoveForward");
const FName AAventuraUSFX022026L1Pawn::MoveRightBinding("MoveRight");
const FName AAventuraUSFX022026L1Pawn::FireForwardBinding("FireForward");
const FName AAventuraUSFX022026L1Pawn::FireRightBinding("FireRight");

AAventuraUSFX022026L1Pawn::AAventuraUSFX022026L1Pawn()
{
	// === CAMBIO DE APARIENCIA: ahora usa el mesh de plataforma (Shape_Cube) ===
	// Antes: static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	// Nueva escala tipo plataforma
	ShipMeshComponent->SetWorldScale3D(FVector(1.0f, 1.0f, 0.2f));

	// Overlap habilitado para detectar plataformas
	ShipMeshComponent->SetGenerateOverlapEvents(true);

	// Suscribirse al evento de overlap
	ShipMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AAventuraUSFX022026L1Pawn::OnPawnOverlap);

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.5f;
	bCanFire = true;
}

void AAventuraUSFX022026L1Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	// PlayerInputComponent->BindAxis(MoveForwardBinding); // COMENTADO: solo nos movemos izq/der
	PlayerInputComponent->BindAxis(MoveRightBinding);

	// Disparos: mantener ambos por si dispara en varias direcciones
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
}

void AAventuraUSFX022026L1Pawn::Tick(float DeltaSeconds)
{
	// === SOLO MOVIMIENTO EN Y (izquierda/derecha) ===
	// Antes:
	// const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	// const float RightValue = GetInputAxisValue(MoveRightBinding);
	// const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	const float RightValue = GetInputAxisValue(MoveRightBinding);
	// Bloqueamos el eje X (Forward) para que solo se mueva en Y
	const FVector MoveDirection = FVector(0.f, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AAventuraUSFX022026L1Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AAventuraUSFX022026L1Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AAventuraUSFX022026L1Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AAventuraUSFX022026L1Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

//   Pawn vs PlataformaIndestructible -> DESTRUYE la plataforma
//   Pawn vs PlataformaDestructible   -> NO hace nada (la destruye el proyectil)
void AAventuraUSFX022026L1Pawn::OnPawnOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	if (!OtherActor || OtherActor == this) return;

	// Solo destruye si es una plataforma Indestructible
	if (Cast<APlataformaIndestructible>(OtherActor))
	{
		OtherActor->Destroy();
		return;
	}

	// Si es Destructible, el pawn NO la destruye (lo hace el proyectil)
	if (Cast<APlataformaDestructible>(OtherActor))
	{
		return;
	}
}