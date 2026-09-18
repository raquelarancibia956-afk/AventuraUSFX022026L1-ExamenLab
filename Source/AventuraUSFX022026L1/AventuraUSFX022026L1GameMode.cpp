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
#include "Enemigo.h"
#include "Kismet/KismetMathLibrary.h"

AAventuraUSFX022026L1GameMode::AAventuraUSFX022026L1GameMode()
{
	DefaultPawnClass = AAventuraUSFX022026L1Pawn::StaticClass();

	tipoPlataformaActual = 0;
	ClasePlataformaIndestructible = APlataformaIndestructible::StaticClass();
	ClasePlataformaDestructible = APlataformaDestructible::StaticClass();
}

void AAventuraUSFX022026L1GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World == nullptr) return;

	FRotator Rotacion = FRotator::ZeroRotator;

	// ===== PAREDES =====
	Pared1 = World->SpawnActor<APared>(APared::StaticClass(), FVector(650, -950, 160), Rotacion);
	Pared2 = World->SpawnActor<APared>(APared::StaticClass(), FVector(560, 910, 160), Rotacion);
	Pared3 = World->SpawnActor<APared>(APared::StaticClass(), FVector(-2920, 900, 160), Rotacion);
	Pared4 = World->SpawnActor<APared>(APared::StaticClass(), FVector(-2880,-940, 160), Rotacion);

	// ===== ENEMIGO =====
	Enemigo1 = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), FVector(-140, 15, 214), Rotacion);

	// ===== TIMER DE PLATAFORMAS =====
	GetWorldTimerManager().SetTimer(
		TimerHandleSpawn,
		this,
		&AAventuraUSFX022026L1GameMode::SpawnearPlataformaAleatoria,
		IntervaloSpawn,
		true
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

	bool bElegirIndestructible = FMath::RandBool();

	TSubclassOf<APlataforma> ClaseAElegir =
		bElegirIndestructible ? ClasePlataformaIndestructible : ClasePlataformaDestructible;

	if (!ClaseAElegir) return;

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