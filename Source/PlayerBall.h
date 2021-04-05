// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerBall.generated.h"


class ABallPlayerController;
class APrehistoric_BallGameModeBase;
class UCameraComponent;
class USoundCue;
class USphereComponent;
class USpringArmComponent;
class UPrehistoric_BallGameInstance;

UCLASS()
class PREHISTORIC_BALL_API APlayerBall : public APawn
{
	GENERATED_BODY()

private:
	//Components for PlayerBall pawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCam;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Ball;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Dino;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Force", meta = (AllowPrivateAccess = "true"))
	float MovementForce = 100.0f;
	//Forwards vector
	FVector Forwards;
	//Sideways movement vector
	FVector Side;
	//Value determines the impulse force the player can jump
	UPROPERTY(EditAnywhere, Category = "Player Properties")
	float JumpForce = 500.0f;
	//Stores the initial rotation of the spring arm
	FRotator InitialSpringArmRotation;
	// Stores the velocity threshold for when a player can be considered dead. 
	UPROPERTY(EditAnywhere, Category = "Player Properties")
	float DeadZoneZSpeed = 3500;
	//Const value converting 1Ms-1 to Miles in an hour approx
	const float MetersToMilesPerHour = 2.2369;
	//Const value used in collision function to determine when to play bounce sound;
	const int ImpulseSoundThreshold = 1000;
	//Class objects to be used in PlayerBall class
	ABallPlayerController* BallControllerRef;
	APrehistoric_BallGameModeBase* GameModeRef;
	UPrehistoric_BallGameInstance* GameInstanceRef;
	//AudioComponents and USoundBase for sounds
	UAudioComponent* RunAudioComponent;
	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* OnRunSound;
	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* OnJumpSound;
	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* OnBounceSound;
	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundBase* OnPickupSound;
	//Value threshold compared with the speed of the player if less than value then stop running sound
	UPROPERTY(EditAnywhere, Category = "SFX")
	int AudioThresholdSilent = 5;
	//Value threshold compared with run speed used to change pitch as player gets faster.
	UPROPERTY(EditAnywhere, Category = "SFX")
	int AudioPitchThresholdRunSpeed = 13;
	//Called when user presses 'W' or 'S' - Player moves forwards and backwards
	void MoveForward(float Value);
	//Called when user presses 'A' or 'E' - Player moves sideways
	void MoveSide(float Value);
	//Called when user presses 'Q' or 'E' Rotates the camera
	void RotateCamera(float Value);
	//Called when user holds the 'Space' key. Keep held down to charge Jump impulse force
	void ChargeJump(float Value);
	//Called when user releases 'Space' 
	void ReleaseJump();
	//Move function, called when W,A,S,D is pressed
	void Move();
	//DeadZone function returns true when player is dead
	bool IsDeadZone();
	//Null check to prevent erros
	bool NullCheck();
	//Overlap and Collision functiuons to be called when the player collides or overlaps with another collision box. 
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Properties")
	int EggCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player World")
	float TimeElapsed;
	UPROPERTY(EditAnywhere, Category = "Player Properties")
	float JumpChargeRate = 0.02;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force")
	float JumpCharge;
	//TArray's of UMaterialInterface holds different materials to be applied to the player when selected.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	TArray<class UMaterialInterface*> SkinMats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	TArray<class UMaterialInterface*> FaceMats;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Properties")
	TArray<class UMaterialInterface*> BallMats;
	int Score = 0;
	//UFUnctions
	//Returns true when player is falling
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	bool IsFalling();
	//Retrieves EggCount - Called in HUD UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	int GetEggCount();
	//Retrieves the players lives - Called in HUD UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	int GetLives();
	//Retrieves the speed the player is moving in mph - Called in HUD UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	int GetSpeed();
	//Returns a number that will be applied to the score depending on the number of lives lost - Called in LevelClear UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	int GetLiveLostPenalty();
	//Returns the players score for the current level - Called in LevelClear UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	int GetScore();
	//Returns the cumalative score from all levels - Called in LevelClear UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	int GetTotalScore();
	//Returns the angle the player is facing, used in the Animation BP to display correct animation
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	int GetDinoRunAngle();
	//Changes the material on the mesh of the player pawn. - Called in DinoSelect UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player Properties")
	void ChangeMaterial();
	//Retrieves the amount of time remaining in the level - Called in HUD UIWidget BP
	UFUNCTION(BlueprintCallable, Category = "Player World")
	float GetLevelTime();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
