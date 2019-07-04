// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPatroll.h"


// Sets default values
AEnemyPatroll::AEnemyPatroll()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MoveComp = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("MovComponent"));
	SplineComp = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComp"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	RootComponent = MeshComp;

	SplineComp->SetupAttachment(RootComponent);

	// Sets up the type of movement
	MoveComp->BehaviourType = EInterpToBehaviourType::PingPong;

	// duration of movement 
	MoveComp->Duration = 5.0f;
}

// Called when the game starts or when spawned
void AEnemyPatroll::BeginPlay()
{
	Super::BeginPlay();

	FInterpCurveVector V = SplineComp->GetSplinePointsPosition();

	for (int i = 0; i < V.Points.Num(); i++)
	{
		MoveComp->AddControlPointPosition(V.Points[i].OutVal, true);
	}

	// points for creating curve
	MoveComp->AddControlPointPosition(FVector(0, 0, 0), true);
	MoveComp->AddControlPointPosition(FVector(590, 470, 0), true);
	MoveComp->AddControlPointPosition(FVector(590, 470, 520), true);
	MoveComp->AddControlPointPosition(FVector(590, 890, 520), true);
	
	MoveComp->FinaliseControlPoints();
}

// Called every frame
void AEnemyPatroll::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

