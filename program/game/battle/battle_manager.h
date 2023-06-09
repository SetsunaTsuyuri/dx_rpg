#pragma once
#include "battler.h"
#include<memory>
#include<list>

/// <summary>
/// 戦闘の管理者
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
味方と敵、どちらかが全員戦えなくなるまで戦う
勝敗判定フェイズで味方が戦えなければ負け、elseif敵が戦えなければ勝ちとする

素早さ順で入れ替える → カット 味方→敵、配列の若い順に行動する

ターン制バトルステートマシンを作る
�@味方 行動選択→対象選択→行動対象決定
�A敵 行動選択→対象選択→行動対象決定
�B味方、敵、配列番号の若い順に行動順を決定する
�C行動 行動順を見て行動実行 実行時に対象がいない場合、ランダムにターゲットを選ぶ
�D行動後、勝負が付いていたら戦闘終了へ elseif行動実行待ちがいるなら�C、いないなら�@へ
*/
