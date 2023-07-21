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


	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data",meta = (ClampMax = 9,ToolTip = "Num Of Section in the Grid "))
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FVector2D NumOfGridSections;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FVector2D QuadDensity_Lod0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FVector2D QuadDensity_Lod1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FString HeightMapFilePath;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FVector CustomOrigin;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	UMaterialInterface*DefaultMaterial;
	

	
};

