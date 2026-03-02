// Fill out your copyright notice in the Description page of Project Settings.


#include "UE09Test.h"

// Sets default values
AUE09Test::AUE09Test()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


float AUE09Test::Foo()
{
	return 0.0f;
}


// Called when the game starts or when spawned
void AUE09Test::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUE09Test::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

