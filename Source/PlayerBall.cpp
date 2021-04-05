// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBall.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Prehistoric_BallGameInstance.h"
#include "Prehistoric_BallGameModeBase.h"
#include "Prehistoric_Ball/BallPlayerController.h"
#include "Prehistoric_Ball/EggItem.h"
#include "Prehistoric_Ball/Goal.h"

// Sets default values
APlayerBall::APlayerBall()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Setup the Player Components structure
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Player Collider"));
	RootComponent = SphereComp;
	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	Ball->SetupAttachment(RootComponent);
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Ball Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);
	PlayerCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera Component"));
	PlayerCam->SetupAttachment(SpringArmComp);
	Dino = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Dino Skeletal Mesh"));
	Dino->SetupAttachment(SpringArmComp);
	RunAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Player Audio Component"));
	RunAudioComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerBall::BeginPlay()
{
	Super::BeginPlay();
	//Initialize  members on Beginplay()
	GameInstanceRef = Cast<UPrehistoric_BallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	JumpCharge = 0.0f;
	EggCount = 0;
	BallControllerRef = (ABallPlayerController*)GetWorld()->GetFirstPlayerController();
	GameModeRef = Cast<APrehistoric_BallGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	InitialSpringArmRotation = SpringArmComp->GetRelativeRotation();
	//Assign the correct Material to the player
	ChangeMaterial();
	// Called when SphereComp overlaps with another collider 
	if (NullCheck())
	{
		BallControllerRef->DisplayHUD();
		SphereComp->OnComponentHit.AddDynamic(this, &APlayerBall::Collision);
		SphereComp->OnComponentBeginOverlap.AddDynamic(this, &APlayerBall::Overlap);
	}
	if (RunAudioComponent && OnRunSound)
	{
		RunAudioComponent->SetSound(OnRunSound);
	}
}
	
	
// Called every frame
void APlayerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!NullCheck())
	{
		return;
	}
	//Time since level started.
	TimeElapsed += GetWorld()->GetDeltaSeconds();
	//Check if player is dead conditions then deduct 1 from lives
	if (IsDeadZone() || GetLevelTime() <= 0)
	{
		GameInstanceRef->Lives--;
		GameInstanceRef->LivesLost++;
		GameModeRef->Restart();
	}
	//Change the sound of the player running depending on the player run speed. 
	RunAudioComponent->SetPitchMultiplier(GetSpeed() / AudioPitchThresholdRunSpeed);
	//If Player is moving at a speed less than AudioThesholdSilent then stop the Running sound
	if (GetSpeed() < AudioThresholdSilent)
	{
		RunAudioComponent->Stop();
	}
}

// Called to bind functionality to input
void APlayerBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerBall::MoveForward);
	PlayerInputComponent->BindAxis("MoveSide", this, &APlayerBall::MoveSide);
	PlayerInputComponent->BindAxis("ChargeJump", this, &APlayerBall::ChargeJump);
	PlayerInputComponent->BindAxis("Rotate", this, &APlayerBall::RotateCamera);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerBall::ReleaseJump);
	PlayerInputComponent->BindAction("Move", IE_Repeat, this, &APlayerBall::Move);

}

//Called when 'W' or 'S' pressed
void APlayerBall::MoveForward(float Value) 
{
	
	Forwards = FVector(Value * 500.0f * GetWorld()->DeltaTimeSeconds, 0, 0);
	//Apply force on the player to move player forwards or backwards
	Ball->AddForce(Forwards * MovementForce * Ball->GetMass());
	//Rotate Dino mesh depending on the direction the ball is moving.
	if (Value == -1 || Value == 1)
	{
		FRotator DinoRotator = FRotator(0, Forwards.Rotation().Yaw - 90, 0);
		Dino->SetWorldRotation(DinoRotator);
	}
}

//Called when 'A' or 'D' Pressed
void APlayerBall::MoveSide(float Value) 
{

   	Side =  FVector(0,Value*500.0f*GetWorld()->DeltaTimeSeconds,0);
	//Apply force on the player to move player left or right
	Ball->AddForce(Side * MovementForce * Ball->GetMass());
}

void APlayerBall::ChargeJump(float Value) 
{
	//if player pawn isn't falling and 'Space' pressed and JumpCharge value is less than 1 (full bar)
	if (!IsFalling() && Value == 1 && JumpCharge <= 1)
	{
		//Increment the JumpCharge by GetWorld()->DeltaTimeSeconds
		JumpCharge += GetWorld()->DeltaTimeSeconds;
		if (!BallControllerRef->JumpBar)
		{
			return;
		}
		//Display the JumpBar in the viewport.
		if (!BallControllerRef->JumpBar->IsInViewport())
		{
			BallControllerRef->JumpBar->AddToViewport();
		}
	}
}

//if Player pawn Z velocity isn't within the range 1 and -1 then the player can be considered falling and return true.
bool APlayerBall::IsFalling()
{
	return (this->GetVelocity().Z <  1 && this->GetVelocity().Z > -1) ? false : true;
}

//Return true when the player pawn goes beyond the deadzone speed threshold
bool APlayerBall::IsDeadZone()
{
	return this->GetVelocity().Z <= (DeadZoneZSpeed*-1) ? true : false;
}

//bool function if objects not found the return false
bool APlayerBall::NullCheck()
{
	return GameModeRef && BallControllerRef && GameInstanceRef ? true : false;
}

// When 'Space' is released call this function
void APlayerBall::ReleaseJump()
{
	if (!BallControllerRef->JumpBar)
	{
		return;
	}
	BallControllerRef->JumpBar->RemoveFromParent();
	FVector Jump = FVector(0, 0, JumpCharge);
	//Apply impulse force when player releases space to enable ball to jump
	Ball->AddImpulse(Jump * JumpForce * Ball->GetMass());
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnJumpSound, this->GetActorLocation());
	JumpCharge = 0.0;
}

void APlayerBall::Move()
{
	//When user is pressing movement keys 'W, A, S, D' play the Run sound
	if(!RunAudioComponent->IsPlaying())
	{
		RunAudioComponent->Play();
		RunAudioComponent->SetPaused(false);
	}
}

void APlayerBall::RotateCamera(float Value)
{
	//Roate camera when values pressed
	if (Value == 1 || Value == -1)
	{
		SpringArmComp->AddLocalRotation(FRotator(0, Value * 250.0f * GetWorld()->DeltaTimeSeconds, 0));
	}
	//Snap camera back to behind player
	else
	{
		SpringArmComp->SetRelativeRotation(InitialSpringArmRotation);
	}
}

void APlayerBall::Collision(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	//When pawn collides with a collision box that is greater than the ImpulseSoundThreshold then play bounce sound.
	if (NormalImpulse.Z > ImpulseSoundThreshold || NormalImpulse.X < -ImpulseSoundThreshold || NormalImpulse.Y < -ImpulseSoundThreshold)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnBounceSound, this->GetActorLocation());
	}
}

void APlayerBall::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Collect egg
	if (AEggItem* Egg = Cast<AEggItem>(OtherActor))
	{
		OtherActor->Destroy();
		EggCount++;
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), OnPickupSound, this->GetActorLocation());
	}
	//Register player moving through goal
	if (AGoal* Goal = Cast<AGoal>(OtherActor))
	{
		Goal->GoalAchieved();
		if (GameModeRef && BallControllerRef)
		{
			GameModeRef->StageClear(Goal);
			BallControllerRef->DisplayLevelClear();
		}
	}
}

//Returns the number of eggs collected
int APlayerBall::GetEggCount()
{
	return EggCount;
}

//Returns the number of lives the player currently has
int APlayerBall::GetLives()
{	
	return GameInstanceRef->Lives;
}

int APlayerBall::GetSpeed()
{
	// returns the speed (in cm/s (Unreal Units/second).
	// multiply by 0.01 to convert to meters
	// multiply by MetersToMilesPerHour to get ~Mph Value
	return this->GetVelocity().Size() * 0.01 * MetersToMilesPerHour;
}

int APlayerBall::GetLiveLostPenalty()
{
	//Switch statement returns a value depending on how many lives lost to act as a penalty to the score.
	switch (GameInstanceRef->LivesLost)
	{
	case 0:
		return 100;
	case 1:
		return 50;
	case 2:
		return 0;
	default:
		return -50;
	}
}

//Returns the score player has earned in the current level
int APlayerBall::GetScore()
{
	return GetEggCount() + GetLiveLostPenalty() + (int)GetLevelTime();
}

//Returns the Total score player has earned in the game.
int APlayerBall::GetTotalScore()
{

	return GetScore() + GameInstanceRef->TotalScore;
}

int APlayerBall::GetDinoRunAngle()
{
	//Return the negative yaw if Dino is facing player (To display correct animation).
	if (Dino->GetComponentRotation().Yaw < 0)
	{
		return (Side).Rotation().Yaw;
	}
	
	return (Side).Rotation().Yaw * -1;
	
}

float APlayerBall::GetLevelTime()
{
	//return time player has been in level. 
	return GameModeRef->LevelTime-TimeElapsed;
}

void APlayerBall::ChangeMaterial()
{
	//Avoid Array index out of bounds (Reset index back to 0 or to the end of the array)
	if (GameInstanceRef->SkinIndex == SkinMats.Num() )
	{
		GameInstanceRef->SkinIndex = 0;
	}
	else if (GameInstanceRef->SkinIndex < 0)
	{
		GameInstanceRef->SkinIndex = SkinMats.Num() - 1;
	}
	else if (GameInstanceRef->FaceIndex == FaceMats.Num())
	{
		GameInstanceRef->FaceIndex = 0;
	}
	else if (GameInstanceRef->FaceIndex < 0)
	{
		GameInstanceRef->FaceIndex = FaceMats.Num() - 1;
	}
	else if (GameInstanceRef->BallIndex == BallMats.Num())
	{
		GameInstanceRef->BallIndex = 0;
	}
	else if (GameInstanceRef->BallIndex < 0)
	{
		GameInstanceRef->BallIndex = BallMats.Num() - 1;
	}
	//Assign the correct material to the Player Dino
	Dino->SetMaterial(0, SkinMats[GameInstanceRef->SkinIndex]);
	Dino->SetMaterial(1, FaceMats[GameInstanceRef->FaceIndex]);
	Ball->SetMaterial(0, BallMats[GameInstanceRef->BallIndex]);
}
