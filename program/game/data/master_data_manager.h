#pragma once
#include <memory>
#include <vector>
#include "../battle/battler_action.h"

/// <summary>
/// マスターデータの管理者
/// </summary>
class MasterDataManager final
{
public:
	MasterDataManager();
	~MasterDataManager();

	/// <summary>
	/// インスタンスを取得する
	/// </summary>
	/// <returns></returns>
	static MasterDataManager& getInstance();

	/// <summary>
	/// 戦闘者の行動を取得する
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	static BattlerAction& getBattlerAction(const int id);

	void test();

private:
	static std::unique_ptr<MasterDataManager> instance_;

	/// <summary>
	/// 戦闘者の行動
	/// </summary>
	std::vector<std::unique_ptr<BattlerAction>> battlerActions_;
};
