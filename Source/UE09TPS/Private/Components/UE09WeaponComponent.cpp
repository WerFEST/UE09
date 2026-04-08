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

	EquipWeapon();


}


//
void UUE09WeaponComponent::StartFire() 
{
	if ( CurrentWeapon )
	{
		return;

	}

	CurrentWeapon->StartFire();

}


//
void UUE09WeaponComponent::StopFire() 
{
	if ( CurrentWeapon )
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

}


//
void UUE09WeaponComponent::EquipWeapon() 
{

}


//
void UUE09WeaponComponent::AttachWeaponToSocket() 
{

}


//
void UUE09WeaponComponent::SpawnWeapon() 
{

}
