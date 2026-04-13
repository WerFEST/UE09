// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "Components/UE09WeaponComponent.h"
//#include "Components/UE09HealthComponent.h"

#include "UE09BaseCharacter.generated.h"


class UUE09WeaponComponent;
class UUE09HealthComponent;


DECLARE_LOG_CATEGORY_EXTERN(LogBaseCharacter, Log, All);


UCLASS()
class UE09TPS_API AUE09BaseCharacter : public ACharacter
{
	GENERATED_BODY()


	/** METHODS **/

public:
	AUE09BaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Multiplayer **/
	UFUNCTION(Server, Reliable)
	void Server_ActivatePlatformTrigger(class APlatformTrigger* PlatformTrigger, bool bIsActivated);

	UFUNCTION(Client, Reliable)
	void Client_ActivatePlatformTrigger(class APlatformTrigger* PlatformTrigger, bool bIsActivated);
	/** End Multiplayer **/

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnDeath();

	UFUNCTION()
	void HealthChanged( float Health, float HealthDelta ); 

private:


	/** PROPERTIES **/

public:

protected:
	UPROPERTY(EditDefaultsOnly)
	UUE09WeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly)
	UUE09HealthComponent* HealthComponent;

private:

};
