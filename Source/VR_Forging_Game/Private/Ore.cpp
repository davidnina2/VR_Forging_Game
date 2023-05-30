
#include "../Public/Ore.h"

AOre::AOre()
{
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FoundMesh(TEXT("/Game/Game/Mesh/Ore/OreMesh.OreMesh"));
	if (FoundMesh.Succeeded())
	{
		VisualMesh->SetStaticMesh(FoundMesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/Game/Material/Ore/M_OreIron.M_OreIron"));
	if (FoundMaterial.Succeeded())
	{
		material = FoundMaterial.Object;
	}
	VisualMesh->SetMaterial(0, material);
	VisualMesh->SetSimulatePhysics(true);
}

void AOre::BeginPlay()
{
	Super::BeginPlay();
}

void AOre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOre::InitializeObject(FString newType, float newCooktime, int newYield)
{
	type=newType;
	cookTime=newCooktime;
	yield=newYield;
	FString materialName;
	switch (oreType.Find(type))
	{
	case 0:
		materialName="/Game/Game/Material/Ore/M_OreIron.M_OreIron";
		break;
	case 1:
		materialName="/Game/Game/Material/Ore/M_OreCopper.M_OreCopper";
		break;
	default:
		materialName="/Game/Game/Material/Ore/M_OreIron.M_OreIron";
		break;
	}
	UMaterial* ConeAsset = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, (TEXT("%s"), *materialName)));
	if (ConeAsset)
	{
		VisualMesh->SetMaterial(0, ConeAsset);
	}
	VisualMesh->SetWorldScale3D(FVector(20, 20, 20));
}

