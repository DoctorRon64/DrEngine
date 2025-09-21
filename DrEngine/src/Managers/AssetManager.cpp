#include "AssetManager.h"

AssetManager::AssetManager() {
    assetFactory = std::make_shared<AssetFactory>();
}

AssetManager::~AssetManager() = default;