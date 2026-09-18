// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AventuraUSFX022026L1GameMode.generated.h"

class APlataforma;
class APared;
class AEnemigo;

UCLASS(MinimalAPI)
class AAventuraUSFX022026L1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAventuraUSFX022026L1GameMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	TArray<APlataforma*> PlataformasAleatorias;

	FTimerHandle TimerEliminarPlataforma;
	APared* Pared1;
	APared* Pared2;
	APared* Pared3;
	APared* Pared4;
	AEnemigo* Enemigo1;

	int tipoPlataformaActual;

	// Clases de plataformas a spawnear
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<APlataforma> ClasePlataformaIndestructible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<APlataforma> ClasePlataformaDestructible;

	// Rango de spawn aleatorio
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	FVector RangoSpawnMin = FVector(-900.0f, -900.0f, 214.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	FVector RangoSpawnMax = FVector(1500.0f, 1200.0f, 300.0f);

	// Intervalo de spawn (segundos)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float IntervaloSpawn = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnearPlataformaAleatoria();

private:
	FTimerHandle TimerHandleSpawn;
};