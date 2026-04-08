// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UE09BaseWeapon.generated.h"


UCLASS()
class UE09TPS_API AUE09BaseWeapon : public AActor
{
	GENERATED_BODY()


	/** METHODS **/

public:

	AUE09BaseWeapon();

	void StartFire();
	void StopFire();

	void Reload();
	bool IsCanReload() const;
	bool IsClipEmpty() const;

	void DecreaseAmmo();

	void MakeShot();

protected:

	virtual void BeginPlay() override;



	/** PROPERTIES **/

public:


protected:

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "UE09|Component" )
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "UE09|Weapon" )
	float TimeBetweenShots = 0.3f;

private:

};
