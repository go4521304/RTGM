// Fill out your copyright notice in the Description page of Project Settings.


#include "NotePawn.h"

#include "EngineUtils.h"
#include "NoteManager.h"

// Sets default values
ANotePawn::ANotePawn()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NoteManager = nullptr;
	HittedTime = 0;
}

// Called when the game starts or when spawned
void ANotePawn::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<ANoteManager> ActorIter(GetWorld()); ActorIter; ++ActorIter)
	{
		if (IsValid(*ActorIter))
		{
			NoteManager = *ActorIter;
			break;
		}
	}
}

// Called every frame
void ANotePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANotePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction<FKeyDelegate>(TEXT("Key1"), IE_Pressed, this, &ThisClass::KeyDown, 0, true);
	PlayerInputComponent->BindAction<FKeyDelegate>(TEXT("Key1"), IE_Released, this, &ThisClass::KeyDown, 0, false);
	PlayerInputComponent->BindAction<FKeyDelegate>(TEXT("Key2"), IE_Pressed, this, &ThisClass::KeyDown, 0, true);
	PlayerInputComponent->BindAction<FKeyDelegate>(TEXT("Key2"), IE_Released, this, &ThisClass::KeyDown, 0, false);
	PlayerInputComponent->BindAction<FKeyDelegate>(TEXT("Key3"), IE_Pressed, this, &ThisClass::KeyDown, 0, true);
	PlayerInputComponent->BindAction<FKeyDelegate>(TEXT("Key3"), IE_Released, this, &ThisClass::KeyDown, 0, false);
}

void ANotePawn::KeyDown(int32 InKeyIndex, bool InKeyDown)
{
	InputKey = InKeyDown;
	if (IsValid(NoteManager))
	{
		NoteManager->KeyInput(InKeyIndex, InKeyDown);
	}
}
