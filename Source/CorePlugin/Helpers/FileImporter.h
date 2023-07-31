/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FileImporter.generated.h"

UCLASS()
class COREPLUGIN_API AFileImporter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFileImporter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	static bool ImportHeightMap (const FString& inFilePath, int32 ImageSize, TArray<float>& OutHeightMap );
	
};
