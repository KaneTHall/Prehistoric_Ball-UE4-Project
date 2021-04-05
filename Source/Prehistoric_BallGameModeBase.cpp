// Copyright Epic Games, Inc. All Rights Reserved.
#include "Prehistoric_BallGameModeBase.h"
#include "Prehistoric_BallGameInstance.h"
#include "Prehistoric_Ball/PlayerBall.h"
#include "Prehistoric_Ball/BallPlayerController.h"
#include "Prehistoric_Ball/Goal.h"
#include "Kismet/GameplayStatics.h"

APrehistoric_BallGameModeBase::APrehistoric_BallGameModeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APrehistoric_BallGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	if (BGMSound)
	{
		PlayBGM();
	}
	//Initialize  members on Beginplay()
	GameInstanceRef = Cast<UPrehistoric_BallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	PCRef = Cast<ABallPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	PlayerBallRef = Cast<APlayerBall>(UGameplayStatics::GetPlayerPawn(this, 0));
	GameOver();
}

void APrehistoric_BallGameModeBase::Tick(float DeltaTime)
{

}

//Called when stage is clear, sets the focus to the goal
void APrehistoric_BallGameModeBase::StageClear(AGoal *GoalRef)
{
	PCRef->SetViewTarget(GoalRef);
}

//Function that restarts level
void APrehistoric_BallGameModeBase::Restart()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void APrehistoric_BallGameModeBase::PlayBGM()
{
	//If Background music found play
	if (BGMSound)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), BGMSound);
	}
}

void APrehistoric_BallGameModeBase::GameOver()
{
	//If player lives is equal to 0
	if (GameInstanceRef -> Lives == 0)
	{
		//Display Game over
		PCRef->DisplayGameOver();
	}
}


