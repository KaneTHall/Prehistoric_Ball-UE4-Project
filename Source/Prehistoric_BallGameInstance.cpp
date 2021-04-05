// Fill out your copyright notice in the Description page of Project Settings.


#include "Prehistoric_BallGameInstance.h"

void UPrehistoric_BallGameInstance::Init()
{
	//Initialise Gameinstance variables
	Super::Init();
	Lives = 5;
	LivesLost = 0;
	TotalScore = 0;
	Level = 1;
	SkinIndex = 0;
	FaceIndex = 0;
	BallIndex = 0;
	SFXVolume = 0.5f;
	MusicVolume = 0.5f;
}

