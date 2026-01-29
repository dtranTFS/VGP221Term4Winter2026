// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/GameHUD.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VGP221WINTER2026_API SSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, GameHUD)
	SLATE_ARGUMENT(int, MyInt)
	SLATE_END_ARGS()

	TWeakObjectPtr<class AGameHUD> GameHUD;
	int MyInt;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnIntClicked() const;
	FReply OnQuitClicked() const;

	/*
		---------------- Smary Pointer Cheat Sheet -----------------
	
		Unique Pointers: UniquePtr<T> = UniquePtr<int> score
			- Sole owner of the object
			- Cannot be copied, only moved
			- Automically deallocates memory when it goes out of scope

		Shared Pointers: SharedPtr<T> = SharedPtr<int> score
			- Multiple ownership of an object
			- Can be copied, increasing reference count
			- Automically deallocates memory when it goes out of scope
			- Eg. UI widgets, game object shared across system

		Weak Pointers: WeakPtr<T> = WeakPtr<int> score
			- Non-owning reference to an object
			- Does not affect reference count
			- Prevents circular references
			- Temporary access to memory

		Soft Object Pointers: SoftObjectPtr<T> = SoftObjectPtr<UStaticMesh> HugeLevel_10_its80GB;
			- Reference to an asset that may not be loaded in memory
			- Loads assets on demand
			- Eg. Useful for larget assets or optional content
	*/
};
