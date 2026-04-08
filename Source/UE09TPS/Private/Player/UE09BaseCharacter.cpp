// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/UE09BaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Dev/PlatformTrigger.h"


//
AUE09BaseCharacter::AUE09BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//
	GetCapsuleComponent()->InitCapsuleSize(42.f, 92.0f);

	//
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	//
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	WeaponComponent = CreateDefaultSubobject<UUE09WeaponComponent>(TEXT("WeaponComponent"));
	HealthComponent = CreateDefaultSubobject<UUE09HealthComponent>(TEXT("HealthComponent"));

}


//
void AUE09BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->InitHealthComponent();

	HealthComponent->OnDeath.AddDynamic( this, &AUE09BaseCharacter::OnDeath );
	HealthComponent->OnHealthChanged.AddDynamic( this, &AUE09BaseCharacter::HealthChanged );

}


//
void AUE09BaseCharacter::OnDeath() 
{
	GetCharacterMovement()->DisableMovement();
	GetCapsuleComponent()->SetCollisionResponseToAllChannels( ECollisionResponse::ECR_Ignore );

	GetMesh()->SetCollisionEnabled( ECollisionEnabled::QueryAndPhysics );
	GetMesh()->SetSimulatePhysics( true );

}


//
void AUE09BaseCharacter::HealthChanged( float Health, float HealthDelta ) 
{

}


//
void AUE09BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


//
void AUE09BaseCharacter::Server_ActivatePlatformTrigger_Implementation(APlatformTrigger* PlatformTrigger, bool bIsActivated)
{
	PlatformTrigger->Multicast_SetIsActivated(bIsActivated);

}


//
void AUE09BaseCharacter::Client_ActivatePlatformTrigger_Implementation(APlatformTrigger* PlatformTrigger, bool bIsActivated)
{
	PlatformTrigger->SetIsActivated(bIsActivated);

}

