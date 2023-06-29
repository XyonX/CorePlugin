// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstance.h"
#include "SpawnableActor.generated.h"

UCLASS()
class COREPLUGIN_API ASpawnableActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshActor")
	UStaticMeshComponent*MeshComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshActor")
	UStaticMesh*Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshActor")
	UMaterialInterface*Mat_interface;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshActor")
	UMaterialInstanceDynamic*Mat_Dynamic;

public:
	
	
	void SetMesh(UStaticMesh*inMesh) {Mesh=inMesh;}
	UStaticMesh* GetMesh () {return  Mesh;};

	void SetMaterial (UMaterialInterface*inMat);

	void Init (UStaticMesh*inMesh,UMaterialInterface*inMaterial);
};
