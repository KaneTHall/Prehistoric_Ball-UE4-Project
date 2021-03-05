// Fill out your copyright notice in the Description page of Project Settings.


#include "BallPlayerController.h"
#include "Blueprint/UserWidget.h"



void ABallPlayerController::BeginPlay()
{
    Super::BeginPlay();
      //Display HUD
   HUD = CreateWidget(this, HUDClass);
  
}

void ABallPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABallPlayerController::Pause()
{
    this->SetPause(true);
}

