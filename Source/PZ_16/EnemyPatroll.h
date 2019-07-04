// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InterpToMovementComponent.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyPatroll.generated.h"

UCLASS()
class PZ_16_API AEnemyPatroll : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyPatroll();

	UPROPERTY(VisibleAnywhere)
	UInterpToMovementComponent * MoveComp;

	UPROPERTY(VisibleAnywhere)
	USplineComponent * SplineComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent * MeshComp;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
