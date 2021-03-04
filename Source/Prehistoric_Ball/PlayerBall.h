// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerBall.generated.h"

class ABallPlayerController;
class USphereComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PREHISTORIC_BALL_API APlayerBall : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCam;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Ball;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Force", meta = (AllowPrivateAccess = "true"))
	float MovementForce = 100.0f;
	float JumpForce = 500.0f;
	ABallPlayerController* BallControllerRef;
	

	void MoveForward(float Value);
	void MoveSide(float Value);
	void RotateCamera(float Value);
	void ChargeJump(float Value);
	void ReleaseJump();
	bool IsFalling();

	UFUNCTION()
	void Collision(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Sets default values for this character's properties
	APlayerBall();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force")
	float JumpCharge;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
