// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawnable.h"

#include "Kismet/GameplayStatics.h"

bool USpawnable::Init(UStaticMesh* inMesh,UMaterialInterface*in_Mat_Interface, UTexture2D* inIcon, ETilingType inTilingType,
                      EMeshPivot inMeshPivotPosition, EMeshQuadrant inMeshQuadrantPosition,EMeshAlignment inMeshAlignment)
{
	
	Mesh=inMesh;
	Mat_Interface=in_Mat_Interface;
	Icon=inIcon;
	TilingType=inTilingType;
	MeshPivotPosition=inMeshPivotPosition;
	MeshQuadrantPosition=inMeshQuadrantPosition;
	MeshAlignment=inMeshAlignment;
	
	FRandomStream RandomStream;
	RandomStream.GenerateNewSeed();
	ID = RandomStream.RandRange(0, 999999);
	BoundingBox= Mesh->GetBoundingBox();
	FVector Extents = BoundingBox.GetExtent();

	MeshLength_X=Extents.X*2;
	MeshLength_Y=Extents.Y*2;
	MeshLength_Z=Extents.Z*2;
	PivotOffset_Center =CalculatePivotOffset_Center();
	
	return true;
	
}

bool USpawnable::CreateInstance (UWorld*WorldContext)
{
	FVector SpawnLoc=FVector::Zero();
	Instance= WorldContext->SpawnActorDeferred<ASpawnableActor>(ASpawnableActor::StaticClass(), FTransform(FRotator::ZeroRotator, SpawnLoc));
	Instance->SetSpawnable(this);
	Instance->Init(Mesh,Mat_Interface,ID);
	UGameplayStatics::FinishSpawningActor(Instance, FTransform(FRotator::ZeroRotator, SpawnLoc));
	//Instance->SetActorHiddenInGame(true);
	return true;
}

FVector USpawnable::CalculatePivotOffset_Center()
{
	FVector Offset =FVector::ZeroVector;

	if(MeshPivotPosition==EMeshPivot::Middle)
	{
		return Offset;
	}

	switch (MeshQuadrantPosition)
	{
	case EMeshQuadrant::First :
		{
			return Offset =FVector (MeshLength_X/2,MeshLength_Y/2,0);

		}
		
	case EMeshQuadrant::Second :
		{
			return  Offset =FVector (MeshLength_X/2,-MeshLength_Y/2,0);
		}
	case EMeshQuadrant::Third :
		{
			return Offset =FVector (-MeshLength_X/2,-MeshLength_Y/2,0);
		}
	case EMeshQuadrant::Fourth :
		{
			return  Offset =FVector (-MeshLength_X/2,MeshLength_Y/2,0);
		}
	case EMeshQuadrant::Alligned :
		{
			switch (MeshAlignment)
			{
			case EMeshAlignment::X_Centered :
				{
					return Offset;
				}
			case EMeshAlignment::Y_Centered :
				{
					return Offset;
				}
			case EMeshAlignment::X_Top :
				{
					return Offset = FVector (MeshLength_X/2,0,0);
				}
			case EMeshAlignment::X_Bottom :
				{
					return Offset = FVector (-MeshLength_X/2,0,0);
				}
			case EMeshAlignment::Y_Left :
				{
					return Offset = FVector (0,-MeshLength_Y/2,0);
				}
			case EMeshAlignment::Y_Right :
				{
					return Offset = FVector (0,MeshLength_Y/2,0);
				}
			case EMeshAlignment::NotAlligned :
				{
					 return Offset;
				}

				
			}
		}
		
	}
	return Offset;
}
