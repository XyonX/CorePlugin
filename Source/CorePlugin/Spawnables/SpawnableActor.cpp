/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/


#include "SpawnableActor.h"
#include "Components/InstancedStaticMeshComponent.h"


// Sets default values
ASpawnableActor::ASpawnableActor()
{
	
}

// Called when the game starts or when spawned
void ASpawnableActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawnableActor::SetMaterial(UMaterialInterface* inMat)
{
	InstancedMesh->SetMaterial(0,inMat);
}

void ASpawnableActor::Init(UStaticMesh*inMesh,UMaterialInterface*inMaterial,int32 inSpawnableID)
{
	Mesh=inMesh;
	Mat_interface=inMaterial;
	SpawnableID=inSpawnableID;

	InstancedMesh =  NewObject<UInstancedStaticMeshComponent>(this);
	InstancedMesh->RegisterComponent();
	InstancedMesh->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
	InstancedMesh->SetStaticMesh(Mesh);
	InstancedMesh->SetMaterial(0,Mat_interface);
	InstancedMesh->SetVisibility(true);
}
