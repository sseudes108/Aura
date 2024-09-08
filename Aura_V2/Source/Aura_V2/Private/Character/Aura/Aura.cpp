#include "Character/Aura/Aura.h"

#include "Character/Aura/States/AuraStateIdle.h"
#include "StateMachine/StateBase.h"

#include "GameFramework/CharacterMovementComponent.h"

AAura::AAura(){
    SetUpCharacterMovement();
}

void AAura::BeginPlay(){
	Super::BeginPlay();
    
    CreateStates();
    IniStateMachine(IdleState);
}

void AAura::SetUpCharacterMovement(){
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;

    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;
}

void AAura::CreateStates(){
    Super::CreateStates();

    IdleState = TStrongObjectPtr<UStateBase>(NewObject<UAuraStateIdle>());
}

void AAura::IniStateMachine(const TStrongObjectPtr<UObject>& InitialState){
    Super::IniStateMachine(InitialState);
}

void AAura::UpdateStateHistory(FString NewState){
    Super::UpdateStateHistory(NewState);
}
