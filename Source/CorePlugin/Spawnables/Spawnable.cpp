// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawnable.h"
#include "SpawnableActor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InstancedStaticMeshComponent.h"


	
bool USpawnable::Init(FMeshProperty*MP)
{
	
	Mesh=MP->Mesh;
	Mat_Interface=MP->Mesh->GetMaterial(0);
	Icon=MP->Icon;
	TilingType=MP->TilingType;
	MeshPivotPosition=MP->MeshPivotPosition;
	MeshQuadrantPosition=MP->MeshQuadrantPosition;
	MeshAlignment= MP->MeshAlignment;
	
	FRandomStream RandomStream;
	RandomStream.GenerateNewSeed();
	ID = RandomStream.RandRange(0, 999999);
	BoundingBox= Mesh->GetBoundingBox();
	bSupportProceduralGeneration=MP->bSupportProceduralGeneration;
	FVector Extents = BoundingBox.GetExtent();

	SpawnableTag=MP->MeshTag;
	SupportedSpawnableTags=MP->SupportedMeshTags;

	MeshLength_X=Extents.X*2;
	MeshLength_Y=Extents.Y*2;
	MeshLength_Z=Extents.Z*2;
	PivotOffset_Center =CalculatePivotOffset_Center();
	
	return true;
	
}

bool USpawnable::CalculateSupportedSpawnables( TMap<int32 ,USpawnable*>& inProceduralSpawnables )
{
	if(TilingType ==ETilingType::UnSupported)
	{
		CompatibleMeshTag_Left.Reset();
		CompatibleMeshTag_Right.Reset();
		CompatibleMeshTag_Up.Reset();
		CompatibleMeshTag_Down.Reset();

		return false;
			
	}
	
	for (auto& pair : inProceduralSpawnables)
	{
		USpawnable*Target =pair.Value;
		if(Target==this)
		{
			continue;
		}

		switch (TilingType)
		{
			
		case ETilingType::UnSupported:
			return false;
			
		case ETilingType::BothDirection :
			
				switch (Target->TilingType)
				{
				case ETilingType::UnSupported :
					break;
				case ETilingType::BothDirection :
					CompatibleMeshTag_Left.AddTag(Target->SpawnableTag);
					CompatibleMeshTag_Right.AddTag(Target->SpawnableTag);
					CompatibleMeshTag_Up.AddTag(Target->SpawnableTag);
					CompatibleMeshTag_Down.AddTag(Target->SpawnableTag);
					break;
				case ETilingType::Vertical :

					CompatibleMeshTag_Up.AddTag(Target->SpawnableTag);
					CompatibleMeshTag_Down.AddTag(Target->SpawnableTag);
					break;
				case ETilingType::Horizontal :
					CompatibleMeshTag_Left.AddTag(Target->SpawnableTag);
					CompatibleMeshTag_Right.AddTag(Target->SpawnableTag);
					break;
				}
				break;
		case ETilingType::Vertical :
			
				switch (Target->TilingType)
				{
			case ETilingType::UnSupported :
				break;
			case ETilingType::BothDirection :
				CompatibleMeshTag_Up.AddTag(Target->SpawnableTag);
				CompatibleMeshTag_Down.AddTag(Target->SpawnableTag);
				break;
			case ETilingType::Vertical :
				CompatibleMeshTag_Up.AddTag(Target->SpawnableTag);
				CompatibleMeshTag_Down.AddTag(Target->SpawnableTag);
				break;
			case ETilingType::Horizontal :
				break;
						
				}
				break;
		case ETilingType::Horizontal :
				switch (Target->TilingType)
				{
			case ETilingType::UnSupported :
				break;
			case ETilingType::BothDirection :
				CompatibleMeshTag_Left.AddTag(Target->SpawnableTag);
				CompatibleMeshTag_Right.AddTag(Target->SpawnableTag);
				break;
			case ETilingType::Vertical :
				break;
			case ETilingType::Horizontal :
				CompatibleMeshTag_Left.AddTag(Target->SpawnableTag);
				CompatibleMeshTag_Right.AddTag(Target->SpawnableTag);
				break;
				}
				break;
		}
		
	}
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

bool USpawnable::AddInstance(FTransform SpawnTransform)
{
	if(Instance)
	{
		if(Instance->GetInstanceMesh())
		{
			Instance->GetInstanceMesh()->AddInstance(SpawnTransform,true);
		}
		return true;
	}
	return false;
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
