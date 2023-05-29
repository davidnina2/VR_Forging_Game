// Fill out your copyright notice in the Description page of Project Settings.


#include "Ingot.h"

// Sets default values
AIngot::AIngot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIngot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIngot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

