// Fill out your copyright notice in the Description page of Project Settings.


#include "GridData.h"

void UGridComponents::Init()
{
	Bounds.Min=FVector ( Center.X-Extents.X , Center.Y-Extents.Y,Center.Z);
	Bounds.Max=FVector ( Center.X+Extents.X , Center.Y+Extents.Y,Center.Z);
}

void UGridSection::Init(AActor*Owner,FVector2D InNumOfQuads, FVector2D InNumOfComponents,
	TArray<TArrayView<const FVector>> InSectionVertices)
{
	SectionVertices=InSectionVertices;
	NumOfComponents = InNumOfComponents;
	NumOfQuads=InNumOfQuads;
	Bounds.Min=FVector ( Center.X-Extents.X , Center.Y-Extents.Y,Center.Z);
	Bounds.Max=FVector ( Center.X+Extents.X , Center.Y+Extents.Y,Center.Z);

	for (int YthComp =0 ; YthComp < NumOfComponents.Y ; YthComp++)
	{
		for (int XthComp =0 ; XthComp < NumOfComponents.X ; XthComp++)
		{

			UGridComponents*GridComp = NewObject<UGridComponents>(Owner);
			
			int SecStartY =YthComp*NumOfQuads.Y;
			int SecEndY =(YthComp+1)*NumOfQuads.Y;
			int SecStartX =XthComp*NumOfQuads.X;
			int SecEndX =(XthComp+1)*NumOfQuads.X;

			TArray<TArrayView<const FVector>>ArrayRef;
			for (int InComponentY =SecStartY ; InComponentY <SecEndY;InComponentY++ )
			{
				for (int InComponentX =SecStartX ; InComponentX <SecEndX;InComponentX++ )
				{
					//take the vector ref from the main vertices array and put it to the section array container
                    TArrayView<const FVector> VectorRef= SectionVertices[(InComponentY*NumOfQuads.X)+InComponentX];
				}
			}
			GridComp->ComponentVertices = ArrayRef;
		}
	}

}