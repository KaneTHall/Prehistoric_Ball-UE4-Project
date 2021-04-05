// Fill out your copyright notice in the Description page of Project Settings.


#include "BallPlayerController.h"
#include "Blueprint/UserWidget.h"



void ABallPlayerController::BeginPlay()
{
    Super::BeginPlay();
    //Create JumpBar Widget
   JumpBar = CreateWidget(this, JumpBarClass);
   bPaused = false;
}

void ABallPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    //Called when user Presses 'P'
    InputComponent->BindAction("Pause", IE_Pressed, this, &ABallPlayerController::Pause).bExecuteWhenPaused = true;
    //Called when user presses 'TAB'
    InputComponent->BindAction("Controls", IE_Pressed, this, &ABallPlayerController::ToggleControls);

}

void ABallPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABallPlayerController::Pause()
{
    //if game not paused when function called create Pause Menu UI Widget. 
    if (!bPaused)
    {
        this->SetPause(true);
        PauseMenu = CreateWidget(this, PauseMenuClass);
        PauseMenu->AddToViewport();
        bPaused = true;
        bShowMouseCursor = true;
    }
    //If Game is paused and function is called then remove the Pause Menu and disable Cursor and pause.
    else if(PauseMenu->IsInViewport() && bPaused)
    {
        UE_LOG(LogTemp, Warning, TEXT("TEST"));
        PauseMenu->RemoveFromParent();
        this->SetPause(false);
        bPaused = false;
        bShowMouseCursor = false;
    }
    
}

//Display HUD UI Widget function
void ABallPlayerController::DisplayHUD()
{
    HUD = CreateWidget(this, HUDClass);
    HUD->AddToViewport();
}

//Display Level Clear UI Widget function
void ABallPlayerController::DisplayLevelClear()
{
    this->SetPause(true);
    LevelClear = CreateWidget(this, LevelClearClass);
    LevelClear->AddToViewport();
    bShowMouseCursor = true;
}

//DisplayG Game Over Screen UI Widget functionm
void ABallPlayerController::DisplayGameOver()
{
    this->SetPause(true);
    GameOver = CreateWidget(this, GameOverClass);
    GameOver->AddToViewport();
    bPaused = true;
    bShowMouseCursor = true;
}

//Toggle Controls when called.
void ABallPlayerController::ToggleControls()
{
    if (Controls && Controls->IsInViewport())
    {
        Controls->RemoveFromParent();
        return;
    }
    Controls = CreateWidget(this, ControlsClass);
    Controls->AddToViewport();
}

void ABallPlayerController::DisplayWinScreen()
{
    this->SetPause(true);
    WinScreen = CreateWidget(this, WinScreenClass);
    WinScreen->AddToViewport();
    bPaused = true;
    bShowMouseCursor = true;
}

