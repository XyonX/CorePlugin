// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GridData.Generated.h"


UENUM(BlueprintType)
enum class EGridType : uint8
{
	PlainGird 		UMETA(DisplayName = "Plain"),
	Organic 		UMETA(DisplayName = "Organic"),
	
};

USTRUCT(BlueprintType)
struct FGridData
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FVector2D GridSize;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data",meta = (ClampMax = 9,ToolTip = "Num Of Quad Per 1 Msqr   or 100 Unreal Unitsqr "))
	FVector2D QuadDensity_Lod0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data",meta = (ClampMax = 4,ToolTip = "Num Of Quad Per 1 Msqr   or 100 Unreal Unitsqr "))
	FVector2D QuadDensity_Lod1;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FString HeightMapFilePath;
	FVector CustomOrigin;
	

	
};


/** The Section Will be divided into multiple Subsection  */
UCLASS(BlueprintType)
class COREPLUGIN_API UGridComponents : public UObject
{
	
	GENERATED_BODY()
	
public:

	/* Functions */
	void Init ();

	/** Data */
	FBox Bounds;
	int32 GlobalIndex;
	int32 LocalIndex;
	FVector Location;
	FVector Center;
	FVector Extents;
	TArray<TArrayView<const FVector>> ComponentVertices;
	
};
/* Number Of Subsection of a grid */
UCLASS(BlueprintType)
class COREPLUGIN_API UGridSection : public UObject
{
	
	GENERATED_BODY()
public:
	/* Functions */
	void Init (AActor*Owner, FVector2D InNumOfQuads, FVector2D InNumOfComponents, TArray<TArrayView<const FVector>> InSectionVertices);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Index;
	FVector Center;
	FBox Bounds;
	FVector Extents;
	FVector WorldLocation;
	FVector2D NumOfQuads;
	FVector2D NumOfComponents;

	TArray<TArrayView<const FVector>> SectionVertices;
	UPROPERTY()
	TMap<int32 , UGridComponents* >SubSections;
	
};

