// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaperZDAnimInstance.h"

#include "SelectedCharacter.generated.h"


struct FInputActionValue;


UCLASS()
class PIGPIRATE_API ASelectedCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASelectedCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	/* Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess))
	class UCameraComponent* Camera;

	/* Inputs */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	class UInputAction* QuitAction;

	/* Attack */
	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess))
	// class UBoxComponent* AttackCollisionBox;
	//
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess))
	// UPaperZDAnimSequence* AttackAnimSequence;

	/* HUD */

	/* Instance */

	/* Sound */

	/* Function */

	void Move(const FInputActionValue& Value);
	void JumpStarted(const FInputActionValue& Value);
	void JumpEnded(const FInputActionValue& Value);
	void Attack(const FInputActionValue& Value);

	void UpdateDirection(float MoveDirection);
};
