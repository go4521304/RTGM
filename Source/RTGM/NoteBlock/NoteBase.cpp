// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteBase.h"

ANoteBase::ANoteBase()
{
}

void ANoteBase::BeginPlay()
{
	Super::BeginPlay();
}

void ANoteBase::SetNoteTime(int32 InTime)
{
	NoteTime = InTime;
}

void ANoteBase::UpdateNote(int32 InTime)
{
	if (NoteTime <= InTime)
	{
		SetActorHiddenInGame(true);
	}
	else
	{
		SetActorHiddenInGame(false);
	}
}
