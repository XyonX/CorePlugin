/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CorePlugin/Data/MeshData.h"
#include "Materials/MaterialInstance.h"
#include "SpawnableActor.generated.h"


class USpawnable;

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
	UInstancedStaticMeshComponent* InstancedMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshActor")
	UStaticMesh*Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshActor")
	UMaterialInterface*Mat_interface;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshActor")
	UMaterialInstanceDynamic*Mat_Dynamic;

	UPROPERTY()
	 USpawnable*Spawnable;
	
public:
	USpawnable* GetSpawnable (){return Spawnable;};
	void SetSpawnable (USpawnable*inSpawnable){Spawnable=inSpawnable;};
	
	int32 SpawnableID;

	//TArray<FInstanceData>InstancesData;
	
	void SetMesh(UStaticMesh*inMesh) {Mesh=inMesh;}
	UStaticMesh* GetMesh () {return  Mesh;};
	UInstancedStaticMeshComponent*GetInstanceMesh (){return InstancedMesh;};
	void SetMaterial (UMaterialInterface*inMat);
	void Init (UStaticMesh*inMesh,UMaterialInterface*inMaterial,int32 inID );
};
