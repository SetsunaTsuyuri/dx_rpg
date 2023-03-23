#include "battle_manager.h"

void BattleManager::executeBattle() {
	// �X�e�[�g�}�V���Ő��䂵�Ă݂���
	// �@�퓬�J�n���� �G�𐶂ݏo���ď���������
	// �A�^�[���J�nST ��������΂��遨���s����
	// �B�s���I��ST
	// �C�s�����sST 1��s�����閈�ɏ��s����
	// �D�^�[���I��ST ��������΂��遨���s����
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
