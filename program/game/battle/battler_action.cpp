#include "battler_action.h"

BattlerAction::TargetType BattlerAction::getTargetType() {
	return targetType_;
}

BattlerAction::EffectType BattlerAction::getEffectType() {
	return effectType_;
}

BattlerAction::DependentStatusType BattlerAction::getDependentStatusType() {
	return dependentStatusType_;
}

float BattlerAction::getPower() {
	return power_;
}