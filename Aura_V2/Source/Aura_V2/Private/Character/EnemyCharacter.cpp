#include "Character/EnemyCharacter.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AEnemyCharacter::AEnemyCharacter(){
    // Highlight PostProcess
    BodyMesh = GetMesh();
    BodyMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    BodyMesh->SetCustomDepthStencilValue(250);
    Weapon->SetCustomDepthStencilValue(250);
    // End Highlight PostProcess

    // GAS
    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
    
    AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
    // End GAS
}

void AEnemyCharacter::BeginPlay(){
    Super::BeginPlay();

    AbilitySystemComponent->InitAbilityActorInfo(this,this);
}

// Highlight PostProcess
void AEnemyCharacter::HighLightActor(){
    BodyMesh->SetRenderCustomDepth(true);
    Weapon->SetRenderCustomDepth(true);
}
void AEnemyCharacter::UnHighLightActor(){
    BodyMesh->SetRenderCustomDepth(false);
    Weapon->SetRenderCustomDepth(false);
}
// End Highlight PostProcess