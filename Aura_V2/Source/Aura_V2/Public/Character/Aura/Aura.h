#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Aura.generated.h"

UCLASS()
class AURA_V2_API AAura : public ACharacterBase{
	GENERATED_BODY()
	
public:
	AAura();
	TStrongObjectPtr<UObject> IdleState;

	virtual void UpdateStateHistory(FString NewState) override;
	virtual void IniStateMachine(const TStrongObjectPtr<UObject>& InitialState) override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
protected:
	virtual void BeginPlay() override;
	virtual void CreateStates() override;

private:
	void SetUpCharacterMovement();
	void InitAbilityActorInfo();
};