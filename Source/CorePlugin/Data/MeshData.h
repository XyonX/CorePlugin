#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MeshData.generated.h"

UENUM(BlueprintType)
enum class ESpawnableType : uint8
{
	ManualGeneration		UMETA(DisplayName ="Manual Generation"),
	ProcedruralGeneration	UMETA(DisplayName ="Procedural Generation"),
	
};

UENUM(BlueprintType)
enum class ETilingType : uint8
{
	UnSupported 	UMETA(DisplayName = "Not Tilable"),
	Horizontal 		UMETA(DisplayName = "Horizontal"),
	Vertical 		UMETA(DisplayName = "Vertical"),
	BothDirection	UMETA(DisplayName = "Both Direction"),
	
	
};

UENUM(BlueprintType)
enum class EMeshPivot : uint8
{
	Cornered 		UMETA(DisplayName = "Cornered Centered "),
	Middle 	UMETA(DisplayName = "Middle Centered"),
	
	
};
UENUM(BlueprintType)
enum class EMeshQuadrant : uint8
{
	First 	UMETA(DisplayName = "Mesh At First Local Quadrant"),
	Second 		UMETA(DisplayName = "Mesh At Second Quadrant "),
	Third 		UMETA(DisplayName = "Mesh At Third Quadrant "),
	Fourth 		UMETA(DisplayName = "Mesh At Fourth Quadrant "),
	Alligned	UMETA(DisplayName = " Mesh Is Axis Aligned "),
	
};

UENUM(BlueprintType)
enum class EMeshAlignment : uint8
{
	NotAlligned UMETA(DisplayName = "Not Alligned "),
	X_Centered	UMETA(DisplayName = "Alligned X Centered "),
	Y_Centered	UMETA(DisplayName = "Alligned Y Centered "),
	X_Top		UMETA(DisplayName = "Alligned X Top "),
	X_Bottom		UMETA(DisplayName = "Alligned X Bottom "),
	Y_Left		UMETA(DisplayName = "Alligned Y Left "),
	Y_Right	UMETA(DisplayName = "Alligned with Y Right "),

};



USTRUCT(BlueprintType)
struct FInstanceData
{
	GENERATED_BODY()

	int32 InstanceIndex;
	FVector2D InstanceLocation ;
	
};

USTRUCT(BlueprintType)
struct FMeshProperty : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	UStaticMesh* Mesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	UTexture2D*Icon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TileMesh")
	FGameplayTag MeshTag ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TileMesh")
	FGameplayTagContainer SupportedMeshTags ;
	
	//if mesh if not Centered at 0,0,0 At local Coordinate   then the Offset  required to Centered
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	FVector CenterOffset;

	//if mesh if not aligned  With forwardX  then the angel required to make it ForX
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	FRotator ForwardOffset;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	ETilingType TilingType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshPivot MeshPivotPosition;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshQuadrant MeshQuadrantPosition;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	EMeshAlignment MeshAlignment;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MeshData")
	bool bSupportProceduralGeneration;

	
};

UCLASS(BlueprintType)
class COREPLUGIN_API UMeshData : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>PrefabBuildings;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>Walls;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>Roads1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>Roads2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>Roads3;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>RoadJunction;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>SideWalk1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>SideWalk2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<UStaticMesh*>SideWalk3;
	
};