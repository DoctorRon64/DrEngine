#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "Assets/AssetFactory.h"

class AssetManager {
public:
    AssetManager();
    ~AssetManager();

    template<typename T>
    std::shared_ptr<T> get(const std::string& path);

    template<typename T>
    void registerLoader(const std::string& extension, const std::string& defaultPath);

private:
    std::shared_ptr<AssetFactory> assetFactory;
    std::unordered_map<std::string, std::weak_ptr<void>> cache;
};

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
void AssetManager::registerLoader(const std::string& extension, const std::string& defaultPath) {
    assetFactory->registerLoader<T>(extension, defaultPath);
}