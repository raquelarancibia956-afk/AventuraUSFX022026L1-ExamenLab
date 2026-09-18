// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaIndestructible.generated.h"

UCLASS()
class AVENTURAUSFX022026L1_API APlataformaIndestructible : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaIndestructible();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	
	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	
};