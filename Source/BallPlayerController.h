// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BallPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PREHISTORIC_BALL_API ABallPlayerController : public APlayerController
{
	GENERATED_BODY()

	private:
	virtual void SetupInputComponent() override;

	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Setup Userwidgets
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> JumpBarClass;
	UPROPERTY()
	UUserWidget* JumpBar;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;
	UPROPERTY()
	UUserWidget* HUD;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> PauseMenuClass;
	UPROPERTY()
	UUserWidget* PauseMenu;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LevelClearClass;
	UPROPERTY()
	UUserWidget* LevelClear;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> GameOverClass;
	UPROPERTY()
	UUserWidget* GameOver;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> ControlsClass;
	UPROPERTY()
	UUserWidget* Controls;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenClass;
	UPROPERTY()
	UUserWidget* WinScreen;
	//Pause game function
	void Pause();
	// Display UI functions
	void DisplayHUD();
	void DisplayLevelClear();
	void DisplayGameOver();
	void ToggleControls();
	void DisplayWinScreen();
	// bool value true if game is paused.
	bool bPaused;

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
