// Fill out your copyright notice in the Description page of Project Settings.

#include "PlataformaIndestructible.h"
#include "Components/StaticMeshComponent.h"
#include "AventuraUSFX022026L1Projectile.h"
#include "GameFramework/Pawn.h"
#include "Materials/MaterialInstanceDynamic.h"

APlataformaIndestructible::APlataformaIndestructible()
{
	PrimaryActorTick.bCanEverTick = true;

	tipoPlataforma = ETipoPlataforma::PLATAFORMA_TERRESTRE;

	if (mallaPlataforma)
	{
		mallaPlataforma->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		mallaPlataforma->SetCollisionResponseToAllChannels(ECR_Overlap);

		// Bloquea contra el mundo (para que se apoye donde debe)
		mallaPlataforma->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
		mallaPlataforma->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
		mallaPlataforma->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);

		// === Overlap con el Pawn para que el Pawn pueda destruirla ===
		mallaPlataforma->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

		mallaPlataforma->SetGenerateOverlapEvents(true);
		mallaPlataforma->OnComponentBeginOverlap.AddDynamic(this, &APlataformaIndestructible::OnOverlapBegin);
	}
}

void APlataformaIndestructible::BeginPlay()
{
	Super::BeginPlay();

	if (mallaPlataforma)
	{
		UMaterialInstanceDynamic* MaterialDinamico =
			mallaPlataforma->CreateAndSetMaterialInstanceDynamic(0);

		if (MaterialDinamico)
		{
			// Color verde
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.0f, 1.0f, 0.0f, 1.0f));
		}
	}
}

void APlataformaIndestructible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlataformaIndestructible::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	if (!OtherActor || OtherActor == this) return;

	// === Proyectil: se destruye SOLO el proyectil (la plataforma sobrevive) ===
	AAventuraUSFX022026L1Projectile* Proyectil = Cast<AAventuraUSFX022026L1Projectile>(OtherActor);
	if (Proyectil)
	{
		Proyectil->Destroy();
		return;
	}

	// === Pawn: se destruye la plataforma ===
	if (Cast<APawn>(OtherActor))
	{
		Destroy();
		return;
	}
}