#include "Character/CharacterBase.h"

#include "StateMachine/StateMachine.h"

ACharacterBase::ACharacterBase(){
	SetUpWeaponSkeletalMesh();
	SetUpStateMachine();
}

void ACharacterBase::BeginPlay(){
	Super::BeginPlay();
}

void ACharacterBase::SetUpWeaponSkeletalMesh(){
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), "WeaponHandSocket");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACharacterBase::SetUpStateMachine(){
	StateMachine = CreateDefaultSubobject<UStateMachine>("State Machine");
}

void ACharacterBase::IniStateMachine(const TStrongObjectPtr<UObject>& InitialState){
	if(StateMachine == nullptr){
		SetUpStateMachine();
	}
		
	StateMachine->ChangeState(InitialState);
}

void ACharacterBase::UpdateStateHistory(FString NewState){}
void ACharacterBase::CreateStates(){}