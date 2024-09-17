#include "Character/Aura/Aura.h"

#include "AbilitySystemComponent.h"
#include "Character/Aura/States/AuraStateIdle.h"
#include "StateMachine/StateBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"

AAura::AAura(){
    SetUpCharacterMovement();
}

void AAura::BeginPlay(){
	Super::BeginPlay();
    
    CreateStates();
    IniStateMachine(IdleState);
}

void AAura::SetUpCharacterMovement(){
    UCharacterMovementComponent* CharMovement = GetCharacterMovement();
    
    CharMovement->bOrientRotationToMovement = true;
    CharMovement->RotationRate = FRotator(0.f, 400.f, 0.f);
    CharMovement->bConstrainToPlane = true;
    CharMovement->bSnapToPlaneAtStart = true;

    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;
}

// State Machine
void AAura::CreateStates(){
    Super::CreateStates();

    IdleState = TStrongObjectPtr<UStateBase>(NewObject<UAuraStateIdle>());
}
void AAura::IniStateMachine(const TStrongObjectPtr<UObject>& InitialState){
    Super::IniStateMachine(InitialState);
}
void AAura::UpdateStateHistory(const FString NewState){
    Super::UpdateStateHistory(NewState);
}
//~State Machine

void AAura::PossessedBy(AController* NewController){
    Super::PossessedBy(NewController);

    //Init Ability Actor for the server
    InitAbilityActorInfo();
}

void AAura::OnRep_PlayerState(){
    Super::OnRep_PlayerState();

    //Init Ability Actor for the client
    InitAbilityActorInfo();
}

void AAura::InitAbilityActorInfo(){
    AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
    check(AuraPlayerState);
    AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
    AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
    AttributeSet = AuraPlayerState->GetAttributeSet();
}
