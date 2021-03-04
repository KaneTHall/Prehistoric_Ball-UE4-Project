// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Prehistoric_BallGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PREHISTORIC_BALL_API APrehistoric_BallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	void StageClear();

public:
	// Sets default values for this actor's properties
	APrehistoric_BallGameModeBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
