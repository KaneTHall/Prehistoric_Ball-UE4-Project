// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBall.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Prehistoric_Ball/BallPlayerController.h"
#include "Prehistoric_Ball/EggItem.h"
#include "Prehistoric_Ball/Goal.h"

// Sets default values
APlayerBall::APlayerBall()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Player Collider"));
	RootComponent = SphereComp;
	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	Ball->SetupAttachment(RootComponent);
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Ball Spring Arm Component"));
    SpringArmComp->SetupAttachment(RootComponent);
    PlayerCam = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera Component"));
    PlayerCam->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void APlayerBall::BeginPlay()
{
	Super::BeginPlay();
	JumpCharge = 0.0f;
	BallControllerRef = (ABallPlayerController*)GetWorld()->GetFirstPlayerController();
	// Called when SphereComp overlaps with another collider 
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &APlayerBall::Overlap);
}

// Called every frame
void APlayerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("%f"),JumpCharge);
	//UE_LOG(LogTemp, Warning, TEXT("%f"), this->GetVelocity().Z);
	/***
	*if (IsFalling())
	*{
	*	UE_LOG(LogTemp, Warning, TEXT("Falling"));
	*}
	*else
	*{
	*	UE_LOG(LogTemp, Warning, TEXT("NOT Falling"));
	*}
	***/
	
}

// Called to bind functionality to input
void APlayerBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerBall::MoveForward);
	PlayerInputComponent->BindAxis("MoveSide", this, &APlayerBall::MoveSide);
	PlayerInputComponent->BindAxis("ChargeJump", this, &APlayerBall::ChargeJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerBall::ReleaseJump);
	PlayerInputComponent->BindAxis("Rotate", this, &APlayerBall::RotateCamera);
}

void APlayerBall::MoveForward(float Value) 
{
	FVector Forwards =  FVector(Value*500.0f*GetWorld()->DeltaTimeSeconds,0,0);
	Ball->AddForce(Forwards * MovementForce * Ball->GetMass());
}

void APlayerBall::MoveSide(float Value) 
{
   	FVector Side =  FVector(0,Value*500.0f*GetWorld()->DeltaTimeSeconds,0);
	Ball->AddForce(Side * MovementForce * Ball->GetMass());
}
float Rate = 0.02;
void APlayerBall::ChargeJump(float Value) 
{
	if (JumpCharge < 0 || JumpCharge > 1)
	{
		Rate *= -1;
	}
	if (Value == 1 && !IsFalling())
	{
		if (!BallControllerRef->HUD->IsInViewport())
		{
			BallControllerRef->HUD->AddToViewport();
		}
		JumpCharge += (Rate*Value);
	}
}

bool APlayerBall::IsFalling()
{
	bool bAirBound = (this->GetVelocity().Z <  1 && this->GetVelocity().Z > -1) ? false : true;
	
	return bAirBound;
}

void APlayerBall::ReleaseJump()
{
		BallControllerRef->HUD->RemoveFromParent();
		FVector Jump = FVector(0, 0, JumpCharge * 500.0f * GetWorld()->DeltaTimeSeconds);
		Ball->AddImpulse(Jump * JumpForce * 0.25 * Ball->GetMass());
		JumpCharge = 0.0;
}

void APlayerBall::RotateCamera(float Value)
{
	SpringArmComp->AddLocalRotation(FRotator(0, Value * 500.0f * GetWorld()->DeltaTimeSeconds, 0));
}

void APlayerBall::Collision(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{

}

void APlayerBall::Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapp"));
	if (AEggItem* Egg = Cast<AEggItem>(OtherActor))
	{
		OtherActor->Destroy();
	}
	if (AGoal* Goal = Cast<AGoal>(OtherActor))
	{
		Goal->GoalAchieved();
	}
}