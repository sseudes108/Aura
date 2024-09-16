#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UStateMachine;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class AURA_V2_API ACharacterBase : public ACharacter{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	TObjectPtr<UStateMachine> StateMachine;
	virtual void CreateStates();
	virtual void IniStateMachine(const TStrongObjectPtr<UObject>& InitialState);

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

public:
	TArray<FString> StateHistory;
	int8 HistoryLenght = 5;
	virtual void UpdateStateHistory(const FString NewState);

private:
	void SetUpWeaponSkeletalMesh();
	void SetUpStateMachine();
};