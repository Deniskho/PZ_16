// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "PZ_16GameMode.h"
#include "PZ_16HUD.h"
#include "PZ_16Character.h"
#include "UObject/ConstructorHelpers.h"

APZ_16GameMode::APZ_16GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APZ_16HUD::StaticClass();
}
