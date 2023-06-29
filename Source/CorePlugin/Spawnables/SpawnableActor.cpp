// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnableActor.h"


// Sets default values
ASpawnableActor::ASpawnableActor()
{

	MeshComponent= CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
	RootComponent->SetMobility(EComponentMobility::Movable);
	
}

// Called when the game starts or when spawned
void ASpawnableActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASpawnableActor::SetMaterial(UMaterialInterface* inMat)
{
	MeshComponent->SetMaterial(0,inMat);
}

void ASpawnableActor::Init(UStaticMesh*inMesh,UMaterialInterface*inMaterial)
{
	Mesh=inMesh;
	Mat_interface=inMaterial;
	
	if(MeshComponent)
	{
		MeshComponent->SetStaticMesh(Mesh);
		MeshComponent->SetMaterial(0,inMaterial);
	}
}
