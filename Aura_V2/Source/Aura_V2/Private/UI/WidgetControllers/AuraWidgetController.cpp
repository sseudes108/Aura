#include "UI/WidgetControllers/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetParams(const FWidgetControllerParams& WidgetControllerParams){
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}