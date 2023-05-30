// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ore.generated.h"

UCLASS()
class VR_FORGING_GAME_API AOre : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOre();
	FString type="Iron";
	float cookTime=5.0f;
	int yield=1;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;
	UPROPERTY(EditAnywhere)
	class UMaterial* material;
	TArray<FString> oreType = {"Iron","Copper"};
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void InitializeObject(FString newType,float newCooktime,int newYield);
};
