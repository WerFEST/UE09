// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UE09TPS.h"

#include "UE09HealthComponent.generated.h"


DECLARE_LOG_CATEGORY_EXTERN( LogUE09HealthComponent, All, All )


class UDamageType;
class AController;


UCLASS( ClassGroup = ( Custom ), meta = ( BlueprintSpawnableComponent ) )
class UE09TPS_API UUE09HealthComponent : public UActorComponent
{
	GENERATED_BODY()


	/** METHODS **/

public:

	UUE09HealthComponent();

	UFUNCTION()
	void InitHealthComponent();


protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	void GetDamage( AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy,
					AActor* DamageCauser );

	UFUNCTION()
	void SetHealth( float newHealth );

	UFUNCTION()
	FORCEINLINE float GetHealth() const
	{
		return Health;
	}

	UFUNCTION()
	bool IsDead() const
	{
		return FMath::IsNearlyZero( Health );
	}

	/** PROPERTIES **/

public:

	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly )
	float MaxHealth = 100.0f;

	FOnDeathSignature OnDeath;

	FOnHealthChangedSignature OnHealthChanged;


protected:

private:

	UPROPERTY()
	float Health = 0.0f;
};
