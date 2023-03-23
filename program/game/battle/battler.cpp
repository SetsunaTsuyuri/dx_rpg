#include "battler.h"
#include "battler_action.h"
#include <memory>
#include <vector>
#include <algorithm>
#include "../data/master_data_manager.h"

Battler::Battler() {
	
	setMaxHP(100);
	setCurrentHP(getMaxHP());

	setPhysicalAttack(20);
	setMagicalAttack(10);
}

const int Battler::getMaxHP() {
	return maxHP_;
}

void Battler::setMaxHP(const int value) {
	maxHP_ = value;
}

const int Battler::getCurrentHP() {
	return currentHP_;
}

void Battler::setCurrentHP(int value) {
	value = std::clamp(value, 0, maxHP_);
	currentHP_ = value;
}

const int Battler::getPhysicalAttack() {
	return physicalAttack;
}

void Battler::setPhysicalAttack(const int value) {
	physicalAttack = value;
}

const int Battler::getMagicalAttack() {
	return magicalAttack_;
}

void Battler::setMagicalAttack(const int value) {
	magicalAttack_ = value;
}

void Battler::act(const int actionId, std::vector<Battler>& targets) {

	// マスターデータから行動を取得する
	BattlerAction& action = MasterDataManager::getBattlerAction(actionId);

	// 行動内容を解決する
	for (Battler& target : targets)
	{
		resolveAction(action, target);
	}
}

void Battler::resolveAction(BattlerAction& action, Battler& target) {

	// ステータス
	int status = 0;
	switch (action.getDependentStatusType()) {
	
	case BattlerAction::DependentStatusType::Physical:
		status = getPhysicalAttack();
		break;

	case BattlerAction::DependentStatusType::Magical:
		status = getMagicalAttack();
		break;

	default:
		break;
	}

	// 効果量
	int value = status * action.getPower();
	
	// 効果適用
	switch (action.getEffectType()) {

	// ダメージ
	case BattlerAction::EffectType::Damage:
		target.takeDamage(value);
		break;

	// 回復
	case BattlerAction::EffectType::Healing:
		target.heal(value);
		break;

	default:
		break;
	}
}

void Battler::takeDamage(const int value) {

	setCurrentHP(getCurrentHP() - value);
}

void Battler::heal(const int value) {

	setCurrentHP(getCurrentHP() + value);
}

const std::vector<int>& Battler::getSkillIds() {
	return skillIds_;
}

const bool& Battler::canFight() {
	return currentHP_ > 0;
}