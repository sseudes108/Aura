#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interfaces/InteractableActor.h"

AAuraPlayerController::AAuraPlayerController(){
    bReplicates = true;
}

void AAuraPlayerController::BeginPlay(){
    Super::BeginPlay();
    SetInputMappingContext();
}

void AAuraPlayerController::PlayerTick(float DeltaTime){
    Super::PlayerTick(DeltaTime);
    CursorTrace();
}

void AAuraPlayerController::CursorTrace(){
    FHitResult CursorHit;
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    if(!CursorHit.bBlockingHit){ return; }
    
    LastActor = CurrentActor;
    CurrentActor = Cast<IInteractableActor>(CursorHit.GetActor());

    if(LastActor == nullptr){
        if(CurrentActor == nullptr){
            return;
        }

        CurrentActor->HighLightActor();
    }else{
        if(CurrentActor == nullptr){
            LastActor->UnHighLightActor();
            return;
        }

        if(LastActor != nullptr){
            LastActor->UnHighLightActor();
            CurrentActor->HighLightActor();
            return;
        }
    }
}

void AAuraPlayerController::SetInputMappingContext(){
    check(AuraContext);

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    check(Subsystem);
    Subsystem->AddMappingContext(AuraContext, 0);

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent(){
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move );
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue){    
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

    const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    if(APawn* ControlledPawn = GetPawn<APawn>()){
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
        ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
    }
}