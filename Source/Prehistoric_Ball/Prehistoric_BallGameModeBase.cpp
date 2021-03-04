// Copyright Epic Games, Inc. All Rights Reserved.
#include "Prehistoric_BallGameModeBase.h"

APrehistoric_BallGameModeBase::APrehistoric_BallGameModeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APrehistoric_BallGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void APrehistoric_BallGameModeBase::Tick(float DeltaTime)
{

}

