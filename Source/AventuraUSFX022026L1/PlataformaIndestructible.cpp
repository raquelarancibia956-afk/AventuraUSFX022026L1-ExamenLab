// Fill out your copyright notice in the Description page of Project Settings.

#include "PlataformaIndestructible.h"
#include "Components/StaticMeshComponent.h"
#include "AventuraUSFX022026L1Projectile.h"

APlataformaIndestructible::APlataformaIndestructible()
{
	PrimaryActorTick.bCanEverTick = true;

	tipoPlataforma = ETipoPlataforma::PLATAFORMA_TERRESTRE;

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
			MaterialDinamico->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.0f, 1.0f, 0.0f, 1.0f)); // Verde
			// O usa SetVectorParameterValue con el nombre del parámetro de tu material
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
    // If overlapped by a projectile, destroy the projectile but not the platform
	AAventuraUSFX022026L1Projectile* Proyectil = Cast<AAventuraUSFX022026L1Projectile>(OtherActor);
	if (Proyectil)
	{
		Proyectil->Destroy();
	}
}
