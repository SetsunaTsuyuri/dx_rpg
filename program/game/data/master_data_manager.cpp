#include "master_data_manager.h"
#include "../../dxlib_ext/dxlib_ext.h"

std::unique_ptr<MasterDataManager> MasterDataManager::instance_ = nullptr;

MasterDataManager::MasterDataManager() { }
MasterDataManager::~MasterDataManager() { }

MasterDataManager& MasterDataManager::getInstance() {
	if (instance_ == nullptr) {
		instance_ = std::make_unique<MasterDataManager>();
	}
	return *instance_;
}

BattlerAction& MasterDataManager::getBattlerAction(const int id) {
	return *getInstance().battlerActions_[id];
}

void MasterDataManager::test() {
	DrawStringEx(50, 50, -1, "test");
}
