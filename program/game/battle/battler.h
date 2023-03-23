#pragma once
#include <memory>
#include <vector>
#include "battler_action.h"

/// <summary>
/// 戦闘者
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
	/// 行動する
	/// </summary>
	/// <param name="actionId"></param>
	/// <param name="targets"></param>
	void act(const int actionId, std::vector<Battler>& targets);

	/// <summary>
	/// ダメージを受ける
	/// </summary>
	/// <param name="value"></param>
	void takeDamage(const int value);

	/// <summary>
	/// 回復する
	/// </summary>
	/// <param name="value"></param>
	void heal(const int value);

	const std::vector<int>& getSkillIds();

	/// <summary>
	/// 戦える
	/// </summary>
	/// <returns></returns>
	const bool& canFight();

private:

	/// <summary>
	/// 最大HP
	/// </summary>
	int maxHP_ = 0;

	/// <summary>
	/// 現在HP
	/// </summary>
	int currentHP_ = 0;

	/// <summary>
	/// 攻撃力
	/// </summary>
	int physicalAttack = 0;

	/// <summary>
	/// 魔力
	/// </summary>
	int magicalAttack_ = 0;

	/// <summary>
	/// スキルIDベクター
	/// </summary>
	std::vector<int> skillIds_;

	/// <summary>
	/// 行動を解決する
	/// </summary>
	/// <param name="action"></param>
	/// <param name="target"></param>
	void resolveAction(BattlerAction& action, Battler& target);
};
