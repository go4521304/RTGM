// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NotePawn.generated.h"

UCLASS()
class RTGM_API ANotePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANotePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	DECLARE_DELEGATE_TwoParams(FKeyDelegate, int32, bool);
	void KeyDown(int32 InKeyIndex, bool InKeyDown);

	// ������ Ű���� ������ �ؾ������� ������ ������Ÿ������ �Է¿��θ� �Ǵ�
	bool InputKey = false;

	class ANoteManager* NoteManager;

	int32 HittedTime;

};
