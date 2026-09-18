// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"
#include "AventuraUSFX022026L1Projectile.h"
#include "Engine/StaticMesh.h"

// Sets default values
AEnemigo::AEnemigo()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

    Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
    RootComponent = Malla;

    // ===== VALORES INICIALES =====
    bVivo = true;
    Direccion = FVector(1.0f, 0.0f, 0.0f);              // Se mueve hacia +X
    LimiteMovimiento = FVector(800.0f, 800.0f, 0.0f);   // Rebota en ±800 en X e Y
    Vida = 10;
    Velocidad = 200.0f;

    SetMalla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

    // ===== COLISIÓN =====
    Malla->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Malla->SetCollisionResponseToAllChannels(ECR_Block);
    Malla->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    Malla->SetGenerateOverlapEvents(true);
    Malla->OnComponentBeginOverlap.AddDynamic(this, &AEnemigo::OnOverlapBegin);
}

void AEnemigo::SetMalla(TCHAR* ruta)
{
    ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(ruta);
    if (Mesh.Succeeded())
    {
        Malla->SetStaticMesh(Mesh.Object);
    }
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
    Super::BeginPlay();

    // Guardar la posición inicial para el rebote
    PosicionInicial = GetActorLocation();
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Solo moverse si está vivo
    if (bVivo)
    {
        Moverse(DeltaTime);
    }
}

// ===== MOVIMIENTO CON REBOTE =====
void AEnemigo::Moverse(float DeltaTime)
{
    FVector PosicionActual = GetActorLocation();

    // Rebote en X
    if (FMath::Abs(PosicionActual.X - PosicionInicial.X) > LimiteMovimiento.X)
    {
        Direccion.X = -Direccion.X;
    }

    // Rebote en Y
    if (FMath::Abs(PosicionActual.Y - PosicionInicial.Y) > LimiteMovimiento.Y)
    {
        Direccion.Y = -Direccion.Y;
    }

    // Nueva posición
    FVector NuevaPosicion = PosicionActual + (Direccion * Velocidad * DeltaTime);
    SetActorLocation(NuevaPosicion);
}


void AEnemigo::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult
)
{
    if (!OtherActor || OtherActor == this) return;

    // Si lo toca un proyectil ? recibe daño y el proyectil se destruye
    //if (Cast<AAventuraUSFX022026L1Projectile>(OtherActor))
    //{
   
    //    OtherActor->Destroy();     // destruir el proyectil
    //}
}