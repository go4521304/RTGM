// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NoteManager.generated.h"

const int32 ms_time = 1000;

USTRUCT()
struct FNoteStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 Time;

	UPROPERTY(EditAnywhere)
	int32 NoteType;
};

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
	UStaticMesh* NoteBlockAsset;

	UPROPERTY(EditAnywhere)
	bool bStartGame;

	// sec
	UPROPERTY(EditAnywhere)
	int32 NoteVisibleSecond;
	// 시작지점에서 어디부터 보일건지 (임시로 X방향에 둘거임 추후 FVector 로 수정예정)
	UPROPERTY(EditAnywhere)
	float NoteStartPosition;

	int32 TimeSec = 0;
	int32 NoteTimeIndex = 0;

	// Time / NoteType
	UPROPERTY(EditAnywhere)
	TArray<FNoteStruct> NoteTime;
	// ObjectPool
	UPROPERTY(EditAnywhere)
	TArray<class AActor*> NoteBlock;
};
