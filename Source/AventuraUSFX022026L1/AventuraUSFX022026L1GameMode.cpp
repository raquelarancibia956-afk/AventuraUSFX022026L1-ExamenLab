// Copyright Epic Games, Inc. All Rights Reserved.

#include "AventuraUSFX022026L1GameMode.h"
#include "AventuraUSFX022026L1Pawn.h"
#include "Pared.h"
#include "PlataformaIndestructible.h"
#include "PlataformaDestructible.h"
#include "Plataforma.h"
#include "PlataformaAerea.h"
#include "PlataformaTerrestre.h"
#include "PlataformaSubterranea.h"
#include "PlataformaAcuatica.h"
#include "Kismet/KismetMathLibrary.h"

AAventuraUSFX022026L1GameMode::AAventuraUSFX022026L1GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAventuraUSFX022026L1Pawn::StaticClass();

	tipoPlataformaActual = 0;
	ClasePlataformaIndestructible = APlataformaIndestructible::StaticClass();
	ClasePlataformaDestructible = APlataformaDestructible::StaticClass();
}

void AAventuraUSFX022026L1GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World == nullptr)
	{
		return;
	}

	FRotator Rotacion = FRotator::ZeroRotator;
	FVector SpawnLocation = FVector::ZeroVector;

	Pared1 = World->SpawnActor<APared>(APared::StaticClass(), FVector(90,860,160), Rotacion);
	Pared2 = World->SpawnActor<APared>(APared::StaticClass(), FVector(30,-880,160), Rotacion);

	GetWorldTimerManager().SetTimer(
		TimerHandleSpawn,
		this,
		&AAventuraUSFX022026L1GameMode::SpawnearPlataformaAleatoria,
		IntervaloSpawn,
		true // repetir
	);
}

void AAventuraUSFX022026L1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAventuraUSFX022026L1GameMode::SpawnearPlataformaAleatoria()
{
	UWorld* World = GetWorld();
	if (!World) return;

	// Elegir aleatoriamente entre destructible e indestructible
	bool bElegirIndestructible = FMath::RandBool();

	TSubclassOf<APlataforma> ClaseAElegir =
		bElegirIndestructible ? ClasePlataformaIndestructible : ClasePlataformaDestructible;

	if (!ClaseAElegir) return;

	// Calcular posición aleatoria dentro del rango
	FVector PosicionAleatoria = UKismetMathLibrary::RandomPointInBoundingBox(
		RangoSpawnMin,
		RangoSpawnMax
	);

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	World->SpawnActor<APlataforma>(
		ClaseAElegir,
		PosicionAleatoria,
		FRotator::ZeroRotator,
		SpawnParams
	);
}

