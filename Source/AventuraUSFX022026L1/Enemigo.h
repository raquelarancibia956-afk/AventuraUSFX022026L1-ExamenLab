// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L1_API AEnemigo : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AEnemigo();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void SetMalla(TCHAR* ruta);

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // ===== VIDA =====
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo")
    int Vida = 100;

    // ===== COMPONENTE VISUAL =====
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* Malla;

    // ===== PROPIEDADES DE MOVIMIENTO =====
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo")
    float Velocidad = 200.0f;

    // Dirección actual del movimiento
    FVector Direccion;

    // Límites de movimiento (rebote)
    FVector LimiteMovimiento;

    // Posición inicial (para el rebote)
    FVector PosicionInicial = FVector::ZeroVector;

    // ===== ESTADO =====
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    bool bVivo = true;

    // ===== FUNCIONES =====
    virtual void Moverse(float DeltaTime);
   

    // ===== COLISIÓN CON PROYECTIL =====
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