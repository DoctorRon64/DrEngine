#include "AssetManager.h"

AssetManager::AssetManager() {
    assetFactory = std::make_shared<AssetFactory>();


    //auto config = assetManager->get<XmlAsset>("settings.xml");
}

AssetManager::~AssetManager() = default;

