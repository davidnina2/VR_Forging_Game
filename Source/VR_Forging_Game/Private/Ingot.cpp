// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Ingot.h"

// Sets default values
AIngot::AIngot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Game/Mesh/Ingot/ingot.ingot"));
	if (FoundMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(FoundMesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/Game/Material/M_Iron.M_Iron"));
	if (FoundMaterial.Succeeded())
	{
		material = FoundMaterial.Object;
	}
	VisualMesh->SetMaterial(0, material);
	VisualMesh->SetSimulatePhysics(true);
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

void AIngot::InitializeObject(FString newType)
{
	type=newType;
	FString materialName;
	switch (oreType.Find(type))
	{
	case 0:
		materialName="/Game/Game/Material/M_Iron.M_Iron";
		break;
	case 1:
		materialName="/Game/Game/Material/M_Copper.M_Copper";
		break;
	default:
		materialName="/Game/Game/Material/M_Iron.M_Iron";
		break;
	}
	UMaterial* ConeAsset = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, (TEXT("%s"), *materialName)));
	if (ConeAsset)
	{
		VisualMesh->SetMaterial(0, ConeAsset);
	}
}


