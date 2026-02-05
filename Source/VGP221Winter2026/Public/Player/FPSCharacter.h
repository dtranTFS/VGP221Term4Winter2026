// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HUD/GameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile/FPSProjectile.h"
#include "FPSCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);

UCLASS()
class VGP221WINTER2026_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* FPSMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector MuzzleOffset;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AFPSProjectile> ProjectileClass;
	
	UPROPERTY(EditAnywhere)
	FOnPlayerDied OnPlayerDied;


	UFUNCTION()
	void OnMoveForward(float Value);

	UFUNCTION()
	void OnMoveRight(float Value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void EndJump();

	UFUNCTION()
	void Fire();

	UFUNCTION()
	void OnHurtPlayer(float DamageAmount);

private:
	float Health = 100.0f;
	float MaxHealth = 100.0f;
};
