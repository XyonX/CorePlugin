﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnableActor.h"
#include "CorePlugin/Data/MeshData.h"
#include "UObject/Object.h"
#include "Spawnable.generated.h"

/**
 * 
 */

enum class EMeshPivot : uint8;
enum class EMeshQuadrant : uint8;
enum class ETilingType : uint8;
class SBuildingCard;

//The Data Holding class for Spawnable items in the world
//Should Be initialized Taking the Data Table
// Currently planned to initialized in the game instance class
UCLASS()
class COREPLUGIN_API USpawnable : public UObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION()
	UStaticMesh*GetMesh(){return  Mesh;};
	UFUNCTION()
	void SetMesh(UStaticMesh*inMesh){Mesh=inMesh;};
	
	
	UFUNCTION()
	ASpawnableActor* GetClass()  {return Instance;};
	UFUNCTION()
	void SetClass(ASpawnableActor*inClass){Instance=inClass;};


	UFUNCTION()
	UMaterialInstanceDynamic* GetMaterial_Dynamic () {return Mat_Dynamic;};
	UFUNCTION()
	void SetMaterial_Dynamic (UMaterialInstanceDynamic*inMaterial){Mat_Dynamic=inMaterial;};
	UFUNCTION()
	UMaterialInterface* GetMaterial_Interface () {return Mat_Interface;};
	UFUNCTION()
	void SetMaterial_Interface (UMaterialInterface*inMaterial){Mat_Interface=inMaterial;};

	
	TSharedPtr<SBuildingCard> GetCard (){return  ActorCard;};
	void SetCard (TSharedPtr<SBuildingCard>inCard){ActorCard=inCard;};

	void SetIcon (UTexture2D*inIcon){Icon=inIcon;};
	UTexture2D* GetIcon(){return Icon;};

	int32 GetID(){return ID;};
	void SetD (int32 inID) {ID=inID;};
	ASpawnableActor*GetActor (){return Instance;};
	

	/** The Init_PreBeginPlay is  the funtion cal be called before the world exist   */
	bool Init (UStaticMesh* inMesh,UMaterialInterface*in_Mat_Interface, UTexture2D* inIcon, ETilingType inTilingType,EMeshPivot inMeshPivotPosition, EMeshQuadrant inMeshQuadrantPosition);
	bool CreateInstance (UWorld*WorldContext);


protected:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	UMaterialInterface*Mat_Interface;
	UPROPERTY()
	UTexture2D*Icon;
	UPROPERTY()
	int32 ID ;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	ETilingType TilingType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshPivot MeshPivotPosition;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshQuadrant MeshQuadrantPosition;

	
private:
	
	UPROPERTY()
	ASpawnableActor*Instance;

	TSharedPtr<SBuildingCard>ActorCard;
	
	UPROPERTY()
	UMaterialInstanceDynamic*Mat_Dynamic;
	
};
