#pragma once
#include <memory>
#include <vector>
#include "battler_action.h"

/// <summary>
/// �퓬��
/// </summary>
class Battler {
public:

	Battler();
	~Battler(){}

	const int getMaxHP();
	void setMaxHP(const int value);

	const int getCurrentHP();
	void setCurrentHP(int value);

	const int getPhysicalAttack();
	void setPhysicalAttack(const int value);

	const int getMagicalAttack();
	void setMagicalAttack(const int value);

	/// <summary>
	/// �s������
	/// </summary>
	/// <param name="actionId"></param>
	/// <param name="targets"></param>
	void act(const int actionId, std::vector<Battler>& targets);

	/// <summary>
	/// �_���[�W���󂯂�
	/// </summary>
	/// <param name="value"></param>
	void takeDamage(const int value);

	/// <summary>
	/// �񕜂���
	/// </summary>
	/// <param name="value"></param>
	void heal(const int value);

	const std::vector<int>& getSkillIds();

	/// <summary>
	/// �킦��
	/// </summary>
	/// <returns></returns>
	const bool& canFight();

private:

	/// <summary>
	/// �ő�HP
	/// </summary>
	int maxHP_ = 0;

	/// <summary>
	/// ����HP
	/// </summary>
	int currentHP_ = 0;

	/// <summary>
	/// �U����
	/// </summary>
	int physicalAttack = 0;

	/// <summary>
	/// ����
	/// </summary>
	int magicalAttack_ = 0;

	/// <summary>
	/// �X�L��ID�x�N�^�[
	/// </summary>
	std::vector<int> skillIds_;

	/// <summary>
	/// �s������������
	/// </summary>
	/// <param name="action"></param>
	/// <param name="target"></param>
	void resolveAction(BattlerAction& action, Battler& target);
};
