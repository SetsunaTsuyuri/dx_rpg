#include "battle_manager.h"

void BattleManager::executeBattle() {
	// ステートマシンで制御してみたい
	// �@戦闘開始処理 敵を生み出して初期化する
	// �Aターン開始ST 何かあればする→勝敗判定
	// �B行動選択ST
	// �C行動実行ST 1回行動する毎に勝敗判定
	// �Dターン終了ST 何かあればする→勝敗判定
}

const bool& BattleManager::canContinue() {

	bool result = canFight(allies_) && canFight(enemies_);
	return result;
}

const bool& BattleManager::canFight(const std::list<std::shared_ptr<Battler>>& battlers) {

	bool result = true;
	for (auto& battler : battlers) {
		
		if (!battler.get()->canFight()) {
			result = false;
			break;
		}
	}

	return result;
}
