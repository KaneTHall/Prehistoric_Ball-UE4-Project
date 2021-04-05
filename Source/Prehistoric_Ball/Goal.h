// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"


class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PREHISTORIC_BALL_API AGoal : public AActor
{
	GENERATED_BODY()
	
private:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* GoalFrame;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Goal;

public:
	// Sets default values for this actor's properties
	AGoal();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void GoalAchieved();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* GoalCam;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
