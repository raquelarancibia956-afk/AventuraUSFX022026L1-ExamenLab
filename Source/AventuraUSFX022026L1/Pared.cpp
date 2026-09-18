// Fill out your copyright notice in the Description page of Project Settings.


#include "Pared.h"

// Sets default values
APared::APared()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	// Create mesh component for the projectile sphere
	malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	malla->SetStaticMesh(PlataformaMeshAsset.Object);
	malla->SetupAttachment(RootComponent);
	RootComponent = malla;

	malla->SetWorldScale3D(FVector((- 2042.0f + 1952)/2, 1.0f, 3.0f));   

	

}

// Called when the game starts or when spawned
void APared::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APared::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

