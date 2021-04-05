// Fill out your copyright notice in the Description page of Project Settings.


#include "EggItem.h"
#include "Components/CapsuleComponent.h"
// Sets default values
AEggItem::AEggItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Setup Eggitem Component structure
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Egg Collider"));
	RootComponent = CapsuleComp;
	Egg = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Egg Mesh"));
	Egg->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEggItem::BeginPlay()
{
	Super::BeginPlay();
	//Initialize Egg rotation
	EggRotation = FRotator(0, RotationSpeed, 0);
	QuatRotation = FQuat(EggRotation);
}

// Called every frame
void AEggItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Apply small amount of rotation to item. 
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}

