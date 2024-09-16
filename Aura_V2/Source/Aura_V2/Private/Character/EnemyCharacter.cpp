#include "Character/EnemyCharacter.h"

#include "AbilitySystem/AuraV2AbilitySystemComponent.h"
#include "AbilitySystem/AuraV2AttributeSet.h"

AEnemyCharacter::AEnemyCharacter(){
    BodyMesh = GetMesh();
    BodyMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    BodyMesh->SetCustomDepthStencilValue(250);
    Weapon->SetCustomDepthStencilValue(250);

    AbilitySystemComponent = CreateDefaultSubobject<UAuraV2AbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
    
    AttributeSet = CreateDefaultSubobject<UAuraV2AttributeSet>("AttributeSet");
}

void AEnemyCharacter::BeginPlay(){
    Super::BeginPlay();

    AbilitySystemComponent->InitAbilityActorInfo(this,this);
}

void AEnemyCharacter::HighLightActor(){
    BodyMesh->SetRenderCustomDepth(true);
    Weapon->SetRenderCustomDepth(true);
}

void AEnemyCharacter::UnHighLightActor(){
    BodyMesh->SetRenderCustomDepth(false);
    Weapon->SetRenderCustomDepth(false);
}

