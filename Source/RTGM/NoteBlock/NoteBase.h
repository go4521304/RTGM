// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NoteBase.generated.h"

UCLASS()
class RTGM_API ANoteBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANoteBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void StartGame();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
};
