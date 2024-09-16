#include "Player/AuraV2PlayerState.h"

#include "AbilitySystem/AuraV2AbilitySystemComponent.h"
#include "AbilitySystem/AuraV2AttributeSet.h"

AAuraV2PlayerState::AAuraV2PlayerState(){
	AbilitySystemComponent = CreateDefaultSubobject<UAuraV2AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAuraV2AttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AAuraV2PlayerState::GetAbilitySystemComponent() const{
	return AbilitySystemComponent;
}
