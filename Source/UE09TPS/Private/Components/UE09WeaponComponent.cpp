// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/UE09WeaponComponent.h"
#include "Weapons/UE09BaseWeapon.h"


DEFINE_LOG_CATEGORY_STATIC( LogUE09WeaponComponent, All, All );


//
UUE09WeaponComponent::UUE09WeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


//
void UUE09WeaponComponent::BeginPlay()
{
	Super::BeginPlay();

}


//
void UUE09WeaponComponent::InitWeaponComponent() 
{
	Owner = Cast<AUE09BaseCharacter>( GetOwner() );
	if (!Owner)
	{
		UE_LOG( LogUE09WeaponComponent, Error, TEXT( "WeaponComponent -> Owner not valid" ) );
		return;
	
	}

	SpawnWeapon();

	EquipWeapon( CurrentWeaponIndex );


}


//
void UUE09WeaponComponent::StartFire() 
{
	if ( !CurrentWeapon )
	{
		return;

	}

	CurrentWeapon->StartFire();

}


//
void UUE09WeaponComponent::StopFire() 
{
	if ( !CurrentWeapon )
	{
		return;
	}

	CurrentWeapon->StopFire();

}


//
void UUE09WeaponComponent::Reload()
{
	if ( CurrentWeapon )
	{
		return;
	}

	CurrentWeapon->Reload();

}


//
void UUE09WeaponComponent::NextWeapon() 
{
	if ( Weapons.IsEmpty() )
		return;

	CurrentWeaponIndex = ( CurrentWeaponIndex + 1 ) % Weapons.Num();
	EquipWeapon( CurrentWeaponIndex );

}


//
void UUE09WeaponComponent::EquipWeapon(int32 WeaponIndex) 
{
	if ( Weapons.IsEmpty() || !Weapons.IsValidIndex(WeaponIndex))
		return;

	AUE09BaseWeapon* lNewWeapon = Weapons[ WeaponIndex ];
	if ( !IsValid( lNewWeapon ) )
		return;

	if ( IsValid(CurrentWeapon) && CurrentWeapon != lNewWeapon )
	{
		CurrentWeapon->StopFire();
		AttachWeaponToSocket( CurrentWeapon, WeaponArmorySocketName );

	}

	CurrentWeapon = lNewWeapon;
	AttachWeaponToSocket( CurrentWeapon, WeaponSocketName );

	CurrentWeaponIndex = WeaponIndex;

}


//
void UUE09WeaponComponent::AttachWeaponToSocket( AUE09BaseWeapon* WeaponToEquip, FName SocketName) 
{
	auto lCharMesh = Owner->GetMesh();

	if ( !lCharMesh || !WeaponToEquip )
		return;

	FAttachmentTransformRules lAttachmentRules(EAttachmentRule::SnapToTarget, true);
	WeaponToEquip->AttachToComponent( lCharMesh, lAttachmentRules, SocketName );

}


//
void UUE09WeaponComponent::SpawnWeapon() 
{
	if (!GetWorld()) return;

	for ( auto lWeaponClass : WeaponClasses )
	{
		if ( !lWeaponClass )
			continue;

		AUE09BaseWeapon* lSpawnedWeapon = GetWorld()->SpawnActor<AUE09BaseWeapon>( lWeaponClass );
		if ( !lSpawnedWeapon )
			continue;

		lSpawnedWeapon->SetOwner( Owner );
		AttachWeaponToSocket( lSpawnedWeapon, WeaponArmorySocketName );
		Weapons.Add( lSpawnedWeapon );

	}

}
