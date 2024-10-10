#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"
#include "Character/AuraEnemy.h"

AAuraPlayerController::AAuraPlayerController(){
    bReplicates = true;
}

void AAuraPlayerController::BeginPlay(){
    Super::BeginPlay();
    check(AuraContext);

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if(Subsystem){
        Subsystem->AddMappingContext(AuraContext, 0);
    }

    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}

void AAuraPlayerController::PlayerTick(float DeltaTime){
    Super::PlayerTick(DeltaTime);

    CursorTrace();
}

void AAuraPlayerController::CursorTrace(){
    FHitResult CursorHit;
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    if(!CursorHit.bBlockingHit){ return; }

    LastActor = ThisActor;
    ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

    /**
     * line trace from cursor (Sereval scenarios)
     * A. LastActor is null and ThisActor is null
     *      - Do nothing
     * B. LastActor is null but ThisActor is valid
     *      - HighLight ThisActor
     * C. LastActor is valid but ThisActor is null
     *      - Unhighlight LastActor
     * D. Both are valid, but LastActor is not ThisActor
     *      - Unhighlight LastActor and HighLight ThisActor
     * E. Both are valid and are the same actor
     *      - Do nothing
     */

    if(LastActor == nullptr){
        //Case A.
        if(ThisActor == nullptr){
            return;
        }

        //Case B.
        ThisActor->HighLightActor();

    }else{
        //Case C.
        if(ThisActor == nullptr){
            LastActor->UnhighLightActor();
            return;
        }

        //Case D.
        if(LastActor != ThisActor){
            LastActor->UnhighLightActor();
            ThisActor->HighLightActor();
            return;
        }
        
        //Case E. Do Nothing
    }
}

void AAuraPlayerController::SetupInputComponent(){
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue){
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    if(APawn* ControlledPawn = GetPawn<APawn>()){
        ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
        ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
    }
}