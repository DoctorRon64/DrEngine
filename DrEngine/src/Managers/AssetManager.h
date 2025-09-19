#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "Assets/AssetFactory.h"

class AssetManager {
public:
    AssetManager();

    template<typename T>
    std::shared_ptr<T> get(const std::string& path);

    template<typename T>
    void registerLoader(const std::string& name);

private:
    std::shared_ptr<AssetFactory> assetFactory;
    std::unordered_map<std::string, std::weak_ptr<void>> cache;
};
