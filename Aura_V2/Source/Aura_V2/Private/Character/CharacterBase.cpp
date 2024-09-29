#include "Character/CharacterBase.h"

#include "StateMachine/StateMachine.h"

ACharacterBase::ACharacterBase(){
	SetUpWeaponSkeletalMesh();
	SetUpStateMachine();
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const{
	return AbilitySystemComponent;
}

void ACharacterBase::BeginPlay(){
	Super::BeginPlay();
}

void ACharacterBase::SetUpWeaponSkeletalMesh(){
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), "WeaponHandSocket");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

//State Machine
void ACharacterBase::CreateStates(){}

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
//End State Machine