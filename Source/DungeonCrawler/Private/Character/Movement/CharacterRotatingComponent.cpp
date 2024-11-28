// Copyright Atennop. All Rights Reserved.

#include "Character/Movement/CharacterRotatingComponent.h"
#include "Character/DungeonCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UCharacterRotatingComponent::UCharacterRotatingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCharacterRotatingComponent::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<ADungeonCharacter>(GetOwner());
	
	check(Character != nullptr)
	check(CharacterCamera != nullptr)
}

void UCharacterRotatingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Character->GetCharacterMovement()->bUseControllerDesiredRotation = Character->GetVelocity() != FVector::Zero();
}

void UCharacterRotatingComponent::Rotate(const FVector2D Input) const
{
	Character->AddControllerYawInput(Input.X);
	Character->AddControllerPitchInput(Input.Y);
}
