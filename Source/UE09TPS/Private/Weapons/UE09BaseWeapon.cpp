// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/UE09BaseWeapon.h"
#include "Player/UE09BaseCharacter.h"


DEFINE_LOG_CATEGORY_STATIC( LogUE09BaseWeapon, All, All );


//
AUE09BaseWeapon::AUE09BaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>( "Weapon Mesh" );
	SetRootComponent( WeaponMesh );

}


//
void AUE09BaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	check( WeaponMesh );

	CurrentAmmo = DefaultAmmo;

}


//
void AUE09BaseWeapon::StartFire()
{
	if ( ReloadInProgress || CurrentAmmo.Bullets == 0 )
		return;

	GetWorldTimerManager().SetTimer( ShotTimerHandle, this, &AUE09BaseWeapon::MakeShot, TimeBetweenShots, true, -1.0f );

}


//
void AUE09BaseWeapon::StopFire()
{
	GetWorldTimerManager().ClearTimer( ShotTimerHandle );

}


//
void AUE09BaseWeapon::Reload()
{
	if ( IsClipEmpty() )
	{
		UE_LOG( LogUE09BaseWeapon, Warning, TEXT( "No clips" ) );
		return;

	}

	if (CurrentAmmo.Bullets == DefaultAmmo.Bullets)
	{
		return;

	}

	ReloadInProgress = true;
	WeaponMesh->PlayAnimation( ReloadAnim, false );
	float lReloadAnimTime = ReloadAnim->GetPlayLength();

	GetWorldTimerManager().SetTimer( ReloadTimerHandle, this, &AUE09BaseWeapon::SwitchIsReload, 1.0f, false, lReloadAnimTime );

	CurrentAmmo.Clips--;
	CurrentAmmo.Bullets = DefaultAmmo.Bullets;

}


//
bool AUE09BaseWeapon::IsClipEmpty() const
{
	return CurrentAmmo.Clips == 0;
}


//
void AUE09BaseWeapon::SwitchIsReload() 
{
	ReloadInProgress = !ReloadInProgress;

}


//
void AUE09BaseWeapon::DecreaseAmmo() 
{
	CurrentAmmo.Bullets--;

	if (CurrentAmmo.Bullets == 0)
	{
		UE_LOG( LogUE09BaseWeapon, Warning, TEXT( "Clip is empty" ) );

		StopFire();
		Reload();

		return;

	}

}


//
void AUE09BaseWeapon::MakeShot() 
{
	FVector lTraceStart, lTraceEnd;
	GetTraceData( lTraceStart, lTraceEnd );

	if (bIsTraceShot)
	{
		/** Line Trace Shot **/
		FHitResult lHitResult;
		MakeTraceHit( lHitResult, lTraceStart, lTraceEnd );

	}
	else
	{
		/** Projectile Trace Shot **/
		FRotator lMuzzleRotation = WeaponMesh->GetSocketRotation( MuzzleSocketName );
		CreateProjectile( lTraceStart, lMuzzleRotation );

	}

	WeaponMesh->PlayAnimation( FireAnim, false );

	DecreaseAmmo();

}


//
bool AUE09BaseWeapon::GetTraceData( FVector& TraceStart, FVector& TraceEnd ) const
{
	const auto lBaseCharacter = Cast<AUE09BaseCharacter>( GetOwner() );
	if ( !lBaseCharacter )
		return false;

	TraceStart = GetMuzzleWorldLocation();

	FVector lAimPoint;
	FHitResult lHit;
	if ( !lBaseCharacter->GetAimPoint( lHit, lAimPoint, TraceMaxDistance ) )
		return false;

	FVector lShootDirection = ( lAimPoint - TraceStart ).GetSafeNormal();

	if (lShootDirection.IsNearlyZero())
	{
		lShootDirection = lBaseCharacter->GetBaseAimRotation().Vector();

	}

	TraceEnd = TraceStart + lShootDirection * TraceMaxDistance;
	return true;

}


//
FVector AUE09BaseWeapon::GetMuzzleWorldLocation() const
{
	return WeaponMesh->GetSocketLocation( MuzzleSocketName );

}


//
void AUE09BaseWeapon::MakeTraceHit( FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd ) 
{
	if ( !GetWorld() )
		return;

	FCollisionQueryParams lParams;
	lParams.AddIgnoredActor( GetOwner() );

	GetWorld()->LineTraceSingleByChannel( HitResult, TraceStart, TraceEnd, ECC_Visibility, lParams );
	DrawDebugLine( GetWorld(), TraceStart, TraceEnd, FColor::Red, 1.f, 1.f );

}