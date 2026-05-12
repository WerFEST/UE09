// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Player/UE09BaseCharacter.h"
#include "UE09WeaponComponent.generated.h"


class AUE09BaseWeapon;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE09TPS_API UUE09WeaponComponent : public UActorComponent
{
	GENERATED_BODY()


	/** METHODS **/

public:
	UUE09WeaponComponent();

	UFUNCTION()
	void InitWeaponComponent();

	UFUNCTION()
	void StartFire();

	UFUNCTION()
	void StopFire();

	UFUNCTION()
	void Reload();

	UFUNCTION()
	void NextWeapon();


protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void EquipWeapon( int32 WeaponIndex );

	UFUNCTION()
	void AttachWeaponToSocket( AUE09BaseWeapon* WeaponToEquip, FName SocketName );


private:

	UFUNCTION()
	void SpawnWeapon();



	/** PROPERTIES **/

public:

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = "UE09|Weapons" )
	AUE09BaseWeapon* CurrentWeapon = nullptr;


protected:

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly )
	AUE09BaseCharacter* Owner;

	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite, Category = "UE09|Weapons" )
	TArray<TSubclassOf<AUE09BaseWeapon>> WeaponClasses;

	UPROPERTY(EditDefaultsOnly)
	FName WeaponArmorySocketName = "WeaponArmorySocket";

	UPROPERTY( EditDefaultsOnly )
	FName WeaponSocketName = "WeaponSocket";

	UPROPERTY(BlueprintReadOnly)
	TArray<AUE09BaseWeapon*> Weapons;


private:

	UPROPERTY()
	int32 CurrentWeaponIndex = 0;

};
