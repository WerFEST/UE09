// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE09Test.h"

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
	bool IsClipEmpty() const;
	void SwitchIsReload();

	void DecreaseAmmo();

	void MakeShot();
	bool GetTraceData( FVector& TraceStart, FVector& TraceEnd ) const;

	FVector GetMuzzleWorldLocation() const;

	/** Trace Shot **/
	void MakeTraceHit( FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd );
	/** Projectile Shot **/
	UFUNCTION(BlueprintImplementableEvent)
	void CreateProjectile( FVector StartLocation, FRotator StartRotation );


protected:

	virtual void BeginPlay() override;



	/** PROPERTIES **/

public:


protected:

	UPROPERTY( VisibleAnywhere, BlueprintReadWrite, Category = "UE09|Component" )
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "UE09|Weapon|Animation" )
	UAnimationAsset* FireAnim;

	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "UE09|Weapon|Animation" )
	UAnimationAsset* ReloadAnim;

	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite, Category = "UE09|Weapon" )
	float TimeBetweenShots = 0.3f;

	UPROPERTY( BlueprintReadOnly, Category = "UE09|Weapon" )
	FTimerHandle ShotTimerHandle;

	UPROPERTY( BlueprintReadOnly, Category = "UE09|Weapon" )
	FTimerHandle ReloadTimerHandle;

	bool ReloadInProgress = false;

	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite, Category = "UE09|Weapon" )
	FName MuzzleSocketName = "MuzzleFlash";

	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "UE09|Weapon" )
	float TraceMaxDistance = 1000.0f;

	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "UE09|Weapon" )
	FAmmoData DefaultAmmo{ 30, 3 };

	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite, Category = "UE09|DEBUG" )
	bool bIsTraceShot = true;



private:

	FAmmoData CurrentAmmo;

};
