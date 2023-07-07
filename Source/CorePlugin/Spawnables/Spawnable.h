﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
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
	FBox GetBounds (){return BoundingBox;};
	ASpawnableActor*GetActor (){return Instance;};
	FVector GetPivotOffset_Center (){return PivotOffset_Center;};
	

	/** The Init_PreBeginPlay is  the function cal be called before the world exist   */
	bool Init (FMeshProperty*MP );
	bool CalculateSupportedSpawnables (TMap<int32 ,USpawnable*> inProceduralSpawnables);
	bool CreateInstance (UWorld*WorldContext);
	float MeshLength_X;
	float MeshLength_Y;
	float MeshLength_Z;
	ETilingType GetTilingType () {return TilingType;};
	EMeshPivot GetMeshPivot (){return MeshPivotPosition;};
	EMeshQuadrant GetMeshQuadrantPosition (){return MeshQuadrantPosition;};
	EMeshAlignment GetMeshAlignment (){return MeshAlignment;};
	bool IsAProceduralSpawnable () {return bSupportProceduralGeneration;};

protected:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	UMaterialInterface*Mat_Interface;
	UPROPERTY()
	UTexture2D*Icon;
	UPROPERTY()
	int32 ID ;
	UPROPERTY()
	FBox BoundingBox;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	bool bSupportProceduralGeneration;
	FVector PivotOffset_Center;
	FVector PivotOffset_FirstQuad;
	FGameplayTag SpawnableTag ;
	FGameplayTagContainer SupportedSpawnableTags;
	
	
	FGameplayTagContainer CompatibleMeshTag_Left;
	FGameplayTagContainer CompatibleMeshTag_Right;
	FGameplayTagContainer CompatibleMeshTag_Up;
	FGameplayTagContainer CompatibleMeshTag_Down;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	ETilingType TilingType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshPivot MeshPivotPosition;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshQuadrant MeshQuadrantPosition;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshAlignment MeshAlignment;

	bool bIsShapeIrregular ;

	//protected functions
	FVector CalculatePivotOffset_Center ();

	
private:
	
	UPROPERTY()
	ASpawnableActor*Instance;

	TSharedPtr<SBuildingCard>ActorCard;
	
	UPROPERTY()
	UMaterialInstanceDynamic*Mat_Dynamic;
	
};
