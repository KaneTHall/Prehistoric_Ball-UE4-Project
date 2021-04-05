// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Setup the Goal Components structure
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Goal Collider"));
	RootComponent = BoxComp;
	GoalFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Goal Frame Mesh"));
	GoalFrame->SetupAttachment(RootComponent);
	Goal = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Goal Skeletal Mesh"));
	Goal->SetupAttachment(RootComponent);
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Goal Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);
	GoalCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Goal Camera Component"));
	GoalCam->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Play goal animation when function called
void AGoal::GoalAchieved()
{
	Goal->bPauseAnims = 0;
}

