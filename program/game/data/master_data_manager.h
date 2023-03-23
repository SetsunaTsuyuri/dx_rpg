#pragma once
#include <memory>
#include <vector>
#include "../battle/battler_action.h"

/// <summary>
/// �}�X�^�[�f�[�^�̊Ǘ���
/// </summary>
class MasterDataManager final
{
public:
	MasterDataManager();
	~MasterDataManager();

	/// <summary>
	/// �C���X�^���X���擾����
	/// </summary>
	/// <returns></returns>
	static MasterDataManager& getInstance();

	/// <summary>
	/// �퓬�҂̍s�����擾����
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	static BattlerAction& getBattlerAction(const int id);

	void test();

private:
	static std::unique_ptr<MasterDataManager> instance_;

	/// <summary>
	/// �퓬�҂̍s��
	/// </summary>
	std::vector<std::unique_ptr<BattlerAction>> battlerActions_;
};
