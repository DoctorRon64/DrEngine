#include "AssetManager.h"

AssetManager::AssetManager() {
    assetFactory = std::make_shared<AssetFactory>();
}

template<typename T>
std::shared_ptr<T> AssetManager::get(const std::string &path) {
    auto it = cache.find(path);
    if (it != cache.end()) {
        if (auto sp = it->second.lock()) {
            return std::static_pointer_cast<T>(sp);
        }
    }
    auto asset = assetFactory->request(path);
    cache[path] = asset;
    return std::static_pointer_cast<T>(asset);
}

template<typename T>
void AssetManager::registerLoader(const std::string& name) {
    assetFactory->registerLoader<T>(name);
}