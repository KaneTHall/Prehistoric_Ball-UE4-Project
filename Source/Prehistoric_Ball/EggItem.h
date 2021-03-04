// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EggItem.generated.h"


class UCapsuleComponent;

UCLASS()
class PREHISTORIC_BALL_API AEggItem : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Egg;
	UPROPERTY(EditAnywhere, Category = "Score")
	int Score = 10;
	UPROPERTY(EditAnywhere)
	float RotationSpeed=0.5;
	FRotator EggRotation;
	FQuat QuatRotation;
		
public:
	// Sets default values for this actor's properties
	AEggItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
