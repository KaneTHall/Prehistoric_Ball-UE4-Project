// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Prehistoric_BallGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PREHISTORIC_BALL_API UPrehistoric_BallGameInstance : public UGameInstance
{
	GENERATED_BODY()

	private:

	public:
	//Gameinstance variabels. Retain value while the game runs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	int Lives;
	int LivesLost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	int TotalScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Properties")
	int Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	int SkinIndex; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	int FaceIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	int BallIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Properties")
	float SFXVolume;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Properties")
	float MusicVolume;

	virtual void Init() override;

	protected:
	
};
