#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class AURA_V2_API UAuraAttributeSet : public UAttributeSet{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};


// #pragma once

// #include "CoreMinimal.h"
// #include "AttributeSet.h"
// #include "AbilitySystemComponent.h"
// #include "AuraAttributeSet.generated.h"

// #define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
// 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
// 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
// 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
// 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

// UCLASS()
// class AURA_V2_API UAuraAttributeSet : public UAttributeSet{
// 	GENERATED_BODY()
// public:
// 	UAuraAttributeSet();
// 	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

// 	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital")
// 	FGameplayAttributeData Health;
// 	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
// 	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital")
// 	FGameplayAttributeData MaxHealth;
// 	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);
	
// 	UFUNCTION()
// 	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
// 	UFUNCTION()
// 	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

// 	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital")
// 	FGameplayAttributeData Mana;
// 	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);
// 	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital")
// 	FGameplayAttributeData MaxMana;
// 	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);
	
// 	UFUNCTION()
// 	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
// 	UFUNCTION()
// 	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;	
// };