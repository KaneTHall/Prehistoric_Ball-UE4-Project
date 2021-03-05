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
	

	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> HUDClass;
	UPROPERTY(EditAnywhere)
	UUserWidget* HUD;

	void Pause();


	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
