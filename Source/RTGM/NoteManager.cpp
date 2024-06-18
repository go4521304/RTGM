// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteManager.h"

// Sets default values
ANoteManager::ANoteManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bStartGame = false;
}

// Called when the game starts or when spawned
void ANoteManager::BeginPlay()
{
	Super::BeginPlay();

	if (NoteBlockAssetClass.Get() == nullptr)
	{
		ensure(false);
		return;
	}

	for (int32 NoteLoadIt = 0; NoteLoadIt <= NoteBlockLoadSize; ++NoteLoadIt)
	{
		FActorSpawnParameters ActorSpawnParameters;
		ActorSpawnParameters.Owner = this;
		FVector SpawnLoc = {};
		FRotator SpawnRot = {};
		AActor* SpawnActor = GetWorld()->SpawnActor(NoteBlockAssetClass.Get(), &SpawnLoc, &SpawnRot, ActorSpawnParameters);
		check(IsValid(SpawnActor));
		SpawnActor->SetActorHiddenInGame(true);
		NoteBlock.Add(SpawnActor);
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

	int32 DeltaTimeSec = static_cast<int32>(DeltaTime * 1000);
	TimeSec += DeltaTimeSec;
}
