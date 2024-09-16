#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

#include "AuraV2PlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class AURA_V2_API AAuraV2PlayerState : public APlayerState, public IAbilitySystemInterface{
	GENERATED_BODY()
	
public:
	AAuraV2PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};