#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UStateMachine;

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

public:
	TArray<FString> StateHistory;
	int8 HistoryLentgh = 5;
	virtual void UpdateStateHistory(FString NewState);

private:
	void SetUpWeaponSkeletalMesh();
	void SetUpStateMachine();
};