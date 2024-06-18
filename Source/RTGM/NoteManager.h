// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NoteManager.generated.h"

UCLASS()
class RTGM_API ANoteManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANoteManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void StartGame();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> NoteBlockAssetClass;

	UPROPERTY(EditAnywhere)
	bool bStartGame;

	UPROPERTY(EditAnywhere)
	int32 NoteBlockLoadSize = 100;

	int32 TimeSec = 0;
	TArray<TPair<int32, int32>> NoteList;

	TArray<AActor*> NoteBlock;
};
