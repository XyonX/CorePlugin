// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawnable.h"

bool USpawnable::Init(UStaticMesh* inMesh,UMaterialInterface*in_Mat_Interface, UTexture2D* inIcon, ETilingType inTilingType,
	EMeshPivot inMeshPivotPosition, EMeshQuadrant inMeshQuadrantPosition)
{
	
	Mesh=inMesh;
	Mat_Interface=in_Mat_Interface;
	Icon=inIcon;
	TilingType=inTilingType;
	MeshPivotPosition=inMeshPivotPosition;
	MeshQuadrantPosition=inMeshQuadrantPosition;
	
	FRandomStream RandomStream;
	RandomStream.GenerateNewSeed();
	ID = RandomStream.RandRange(0, 999999);

	return true;
	
}
