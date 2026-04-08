// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/UE09HealthComponent.h"


DEFINE_LOG_CATEGORY( LogUE09HealthComponent )


//
UUE09HealthComponent::UUE09HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


//
void UUE09HealthComponent::BeginPlay()
{
	Super::BeginPlay();

}


//
void UUE09HealthComponent::GetDamage( AActor* DamagedActor, float Damage, const UDamageType* DamageType,
									  AController* InstigatedBy, AActor* DamageCauser )
{
	if ( Damage <= 0.0f || IsDead() )
	{
		return;

	}

	float lNewHealth = Health - Damage;

	UE_LOG( LogUE09HealthComponent, Warning, TEXT( "Actor get %f damage. Current health is: %f" ), Damage, lNewHealth );

	SetHealth( lNewHealth );

	if ( IsDead() )
	{
		OnDeath.Broadcast();
		UE_LOG( LogUE09HealthComponent, Warning, TEXT( "Actor is dead!" ) );

	}

}


//
void UUE09HealthComponent::SetHealth( float newHealth )
{
	float lUpdatedhealth = FMath::Clamp( newHealth, 0.0f, MaxHealth );
	float lHealthDelta = lUpdatedhealth - Health;

	Health = lUpdatedhealth;

	OnHealthChanged.Broadcast( Health, lHealthDelta );

}


//
void UUE09HealthComponent::InitHealthComponent()
{
	AActor* lOwner = GetOwner();

	if ( lOwner )
	{
		lOwner->OnTakeAnyDamage.AddDynamic( this, &UUE09HealthComponent::GetDamage );
		SetHealth( MaxHealth );
		UE_LOG( LogUE09HealthComponent, Warning, TEXT( "Actor HealthComponent was successfully initialized!" ) );

	}

}
