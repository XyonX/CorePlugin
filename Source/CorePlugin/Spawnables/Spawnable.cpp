// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawnable.h"

#include "Kismet/GameplayStatics.h"

bool USpawnable::Init(UStaticMesh* inMesh,UMaterialInterface*in_Mat_Interface, UTexture2D* inIcon, ETilingType inTilingType,
                      EMeshPivot inMeshPivotPosition, EMeshQuadrant inMeshQuadrantPosition)
{
	
	Mesh=inMesh;
	Mat_Interface=in_Mat_Interface;
	Icon=inIcon;
	TilingType=inTilingType;
	MeshPivotPosition=inMeshPivotPosition;
	MeshQuadrantPosition=inMeshQuadrantPosition;
	
	FRandomStream RandomStream;
	RandomStream.GenerateNewSeed();
	ID = RandomStream.RandRange(0, 999999);

	return true;
	
}

bool USpawnable::CreateInstance (UWorld*WorldContext)
{
	FVector SpawnLoc=FVector::Zero();
	Instance= WorldContext->SpawnActorDeferred<ASpawnableActor>(ASpawnableActor::StaticClass(), FTransform(FRotator::ZeroRotator, SpawnLoc));
	Instance->Init(Mesh,Mat_Interface,ID);
	UGameplayStatics::FinishSpawningActor(Instance, FTransform(FRotator::ZeroRotator, SpawnLoc));
	Instance->SetActorHiddenInGame(true);
	return true;
}
