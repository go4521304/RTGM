// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteManager.h"

#include "Engine/StaticMeshActor.h"
#include "NoteBlock/NoteBase.h"

// Sets default values
ANoteManager::ANoteManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	bStartGame = false;
	NoteVisibleSecond = 10;
	NoteStartPosition = 10000.f;

}

// Called when the game starts or when spawned
void ANoteManager::BeginPlay()
{
    Super::BeginPlay();
	
    if (IsValid(NoteBlockAsset) == false)
	{
		ensure(false);
		return;
	}
	
    FActorSpawnParameters ActorSpawnParameters;
    ActorSpawnParameters.Owner = this;
    FVector SpawnLoc = FVector::ZeroVector;
    FRotator SpawnRot = FRotator::ZeroRotator;

	for (const FNoteStruct& NoteTimeIt : NoteTime)
	{
		// todo NoteTimeIt.NoteType 에 따라 나눠서 스폰
		AStaticMeshActor* SpawnedActor = GetWorld()->SpawnActor<AStaticMeshActor>(SpawnLoc, SpawnRot, ActorSpawnParameters);
		check(IsValid(SpawnedActor));
		SpawnedActor->SetMobility(EComponentMobility::Movable);
		SpawnedActor->GetStaticMeshComponent()->SetStaticMesh(NoteBlockAsset);
		NoteBlock.Add(SpawnedActor);
	}
}

void ANoteManager::StartGame()
{
	bStartGame = true;

} 

// Called every frame
void ANoteManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bStartGame == false)
	{
		return;
	}

	int32 DeltaTimeSec = static_cast<int32>(DeltaTime * ms_time);
	TimeSec += DeltaTimeSec;

	UE_LOG(LogTemp, Warning, TEXT("TimeSec : %d"), TimeSec);

	for (int32 NoteIndex = NoteTimeIndex; NoteIndex < NoteTime.Num(); ++NoteIndex)
	{
		const FNoteStruct& NoteTimeIt = NoteTime[NoteIndex];

		if (NoteTimeIt.Time < TimeSec)
		{
			NoteBlock[NoteIndex]->SetActorLocation(FVector::ZeroVector);
			NoteTimeIndex = NoteIndex;
			continue;
		}
		else if (NoteTimeIt.Time > TimeSec + (NoteVisibleSecond * ms_time))
		{
			break;
		}

		FVector NewLocation = GetActorLocation();
		NewLocation.X += NoteStartPosition * (static_cast<float>(NoteTimeIt.Time - TimeSec) / static_cast<float>(NoteVisibleSecond * ms_time));
		NoteBlock[NoteIndex]->SetActorLocation(NewLocation);
	}
}
