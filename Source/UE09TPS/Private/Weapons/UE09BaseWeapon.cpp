// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/UE09BaseWeapon.h"


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
	
}


//
void AUE09BaseWeapon::StartFire()
{

}


//
void AUE09BaseWeapon::StopFire()
{

}


//
void AUE09BaseWeapon::Reload()
{

}


//
bool AUE09BaseWeapon::IsCanReload() const
{
	return false;
}


//
bool AUE09BaseWeapon::IsClipEmpty() const
{
	return false;
}


//
void AUE09BaseWeapon::DecreaseAmmo() 
{

}


//
void AUE09BaseWeapon::MakeShot() 
{

}
