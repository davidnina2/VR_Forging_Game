
#include "../Public/Ore.h"

AOre::AOre()
{
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/Game/Mesh/ingot.ingot"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}*/
}

AOre::AOre(FString newType, float newCooktime, int newYield)
{
	type=newType;
	cookTime=newCooktime;
	yield=newYield;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
}

void AOre::BeginPlay()
{
	Super::BeginPlay();
}

void AOre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

