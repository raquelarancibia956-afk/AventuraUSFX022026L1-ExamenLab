// Fill out your copyright notice in the Description page of Project Settings.

#include "PlataformaDestructible.h"
#include "Components/StaticMeshComponent.h"
#include "AventuraUSFX022026L1Projectile.h"

APlataformaDestructible::APlataformaDestructible()
{
	PrimaryActorTick.bCanEverTick = true;

	tipoPlataforma = ETipoPlataforma::PLATAFORMA_AEREA;

    if (mallaPlataforma)
	{
		// Allow both overlap queries and physics blocking so platforms can both overlap and block
		mallaPlataforma->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		// Default to overlap so existing overlap logic still fires
		mallaPlataforma->SetCollisionResponseToAllChannels(ECR_Overlap);
		// Make common channels block so projectiles or physics objects will hit the platform
		mallaPlataforma->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
		mallaPlataforma->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
		mallaPlataforma->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);
		mallaPlataforma->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
		mallaPlataforma->SetGenerateOverlapEvents(true);
		mallaPlataforma->OnComponentBeginOverlap.AddDynamic(this, &APlataformaDestructible::OnOverlapBegin);
	
	}
}

void APlataformaDestructible::BeginPlay()
{
	Super::BeginPlay();
	if (mallaPlataforma)
	{
		UMaterialInstanceDynamic* MaterialDinamico =
			mallaPlataforma->CreateAndSetMaterialInstanceDynamic(0);

		if (MaterialDinamico)
		{
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor(1.0f, 0.0f, 0.0f, 1.0f)); // Rojo
		}
	}
}


void APlataformaDestructible::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlataformaDestructible::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	AAventuraUSFX022026L1Projectile* Proyectil = Cast<AAventuraUSFX022026L1Projectile>(OtherActor);
	if (Proyectil)
	{
     
		Proyectil->Destroy();
		Destroy();
	}
}