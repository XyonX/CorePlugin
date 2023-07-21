// Fill out your copyright notice in the Description page of Project Settings.


#include "FileImporter.h"
#include "IImageWrapper.h"
#include "Misc/FileHelper.h"


// Sets default values
AFileImporter::AFileImporter()
{
}

// Called when the game starts or when spawned
void AFileImporter::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AFileImporter::ImportHeightMap(const FString& inFilePath, int32 ImageSize, TArray<float>& OutHeightMap)
{
	// Load the image file
	TArray<uint8> FileData;
	if (!FFileHelper::LoadFileToArray(FileData, *inFilePath))
	{
		// Failed to load the file
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "Failed to load the file");
		return false;
	}

	// Calculate the expected size of the raw data based on the desired image size
	int32 ExpectedDataSize = ImageSize * ImageSize * sizeof(uint8);

	if (FileData.Num() != ExpectedDataSize)
	{
		// Invalid data size
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "Invalid data size");
		return false;
	}

	// Clear the height map array
	OutHeightMap.Empty();

	// Iterate through the raw data and extract the height values
	for (int32 i = 0; i < FileData.Num(); ++i)
	{
		// Cast the uint8 value to float and normalize within the range of 0.0 to 1.0
		float Height = static_cast<float>(FileData[i]) / 255.0f;
		// Add the height value to the height map array
		OutHeightMap.Add(Height);
	}
/*
	// Serialize height map
	FBufferArchive MemoryWriter;
	SerializeHeightMap(MemoryWriter);
	MemoryWriter.Flush();

	TArray<uint8> SaveData;
	SaveData.Empty();
	SaveData.Append(MemoryWriter.GetData(), MemoryWriter.Num());

	FString SavePath = FPaths::ProjectSavedDir() + TEXT("Data/HeightMap.sav");
	FFileHelper::SaveArrayToFile(SaveData, *SavePath);*/

	return true;
	
}

