// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Prehistoric_BallGameModeBase.generated.h"

class AGoal;
class APlayerBall;
class ABallPlayerController;
class UPrehistoric_BallGameInstance;

UCLASS()
class PREHISTORIC_BALL_API APrehistoric_BallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	//Create objects to be used in  GameMode class to reference other classes.
	ABallPlayerController* PCRef;
	APlayerBall* PlayerBallRef;
	UPrehistoric_BallGameInstance* GameInstanceRef;
public:
	// Sets default values for this actor's properties
	APrehistoric_BallGameModeBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void StageClear(AGoal* GoalRef);
	//Reload the level 
	void Restart();
	//Variable to hold the amount of time in a level. Initialized in level BP.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Properties")
	float LevelTime; 
	//SoundBase for Background music
	UPROPERTY(EditAnywhere, Category = "Game Properties")
	USoundBase* BGMSound;
	//Function that Plays the background music - Called on BeginPlay()
	void PlayBGM();
	//Called by PlayerBall when Player runs out of lives
	void GameOver();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
