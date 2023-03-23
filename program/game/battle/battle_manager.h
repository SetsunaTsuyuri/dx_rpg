#pragma once
#include "battler.h"
#include<memory>
#include<list>

/// <summary>
/// �퓬�̊Ǘ���
/// </summary>
class BattleManager {

public:

	BattleManager() {}
	~BattleManager() {}

	void executeBattle();

private:

	std::list<std::shared_ptr<Battler>> allies_;

	std::list<std::shared_ptr<Battler>> enemies_;

	const bool& canContinue();

	const bool& canFight(const std::list<std::shared_ptr<Battler>>& battlers);
};

/*
�����ƓG�A�ǂ��炩���S���킦�Ȃ��Ȃ�܂Ő키
���s����t�F�C�Y�Ŗ������킦�Ȃ���Ε����Aelseif�G���킦�Ȃ���Ώ����Ƃ���

�f�������œ���ւ��� �� �J�b�g �������G�A�z��̎Ⴂ���ɍs������

�^�[�����o�g���X�e�[�g�}�V�������
�@���� �s���I�����ΏۑI�����s���Ώی���
�A�G �s���I�����ΏۑI�����s���Ώی���
�B�����A�G�A�z��ԍ��̎Ⴂ���ɍs���������肷��
�C�s�� �s���������čs�����s ���s���ɑΏۂ����Ȃ��ꍇ�A�����_���Ƀ^�[�Q�b�g��I��
�D�s����A�������t���Ă�����퓬�I���� elseif�s�����s�҂�������Ȃ�C�A���Ȃ��Ȃ�@��
*/
