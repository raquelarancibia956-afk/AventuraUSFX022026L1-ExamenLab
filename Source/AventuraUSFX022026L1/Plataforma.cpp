// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
APlataforma::APlataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	// Create mesh component for the projectile sphere
	mallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPlataforma"));
	mallaPlataforma->SetStaticMesh(PlataformaMeshAsset.Object);
	mallaPlataforma->SetupAttachment(RootComponent);
	mallaPlataforma->SetWorldScale3D(FVector(1.0f, 1.0f, 0.2f));
	RootComponent = mallaPlataforma;
	mallaPlataforma->SetGenerateOverlapEvents(true);
	

	movimientoEjes = FVector(1.0f, 0.0f, 0.0f);
	movimientoLimitesMaximos = FVector(FMath::RandRange(200.0f, 800.0f), FMath::RandRange(200.0f, 800.0f), FMath::RandRange(200.0f, 800.0f));
	movimientoLimitesMinimos = FVector(FMath::RandRange(-800.0f, -200.0f), FMath::RandRange(-800.0f, -200.0f), FMath::RandRange(-800.0f, -200.0f));
	movimientoVelocidades = FVector(FMath::RandRange(50.0f, 200.0f), FMath::RandRange(50.0f, 200.0f), FMath::RandRange(50.0f, 200.0f));
	movimientoDireccion = FVector(FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f), FMath::RandRange(-1.0f, 1.0f));
	//movimientoDireccion = FVector(1.0f, 0.0f, 0.0f);

	TiempoTranscurrido = 0.0f;
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TiempoTranscurrido += DeltaTime;

	// Movimiento vertical: sube y baja cada TiempoCiclo segundos
	// Usamos una onda senoidal para que el movimiento sea suave
	float Fase = (TiempoTranscurrido / TiempoCiclo) * 2.0f * PI;
	float DesplazamientoZ = FMath::Sin(Fase) * AlturaMovimiento;

	FVector NuevaPosicion = PosicionInicial;
	NuevaPosicion.Z += DesplazamientoZ;
	SetActorLocation(NuevaPosicion);
}

