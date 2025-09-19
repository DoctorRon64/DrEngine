#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include <stdexcept>
#include "IAssetLoader.h"
#include <type_traits>

class AssetFactory {
public:
    template<typename Loader>
    void registerLoader(const std::string& extension, const std::string& defaultPath);

    std::shared_ptr<void> request(const std::string& fileName);

private:
    std::unordered_map<std::string, std::shared_ptr<IAssetLoader>> loaders;
    std::unordered_map<std::string, std::string> defaultPaths;
};

template<typename Loader>
void AssetFactory::registerLoader(const std::string& extension, const std::string& defaultPath) {
    static_assert(std::is_base_of<IAssetLoader, Loader>::value, "Loader must derive from IAssetLoader");
    loaders[extension] = std::make_shared<Loader>();
    defaultPaths[extension] = defaultPath;
}

inline std::shared_ptr<void> AssetFactory::request(const std::string& fileName) {
    auto dot = fileName.find_last_of('.');
    if (dot == std::string::npos) throw std::runtime_error("File has no extension: " + fileName);

    std::string ext = fileName.substr(dot + 1);

    auto loaderIt = loaders.find(ext);
    if (loaderIt == loaders.end()) throw std::runtime_error("No loader for extension: " + ext);

    std::string fullPath = fileName;
    auto pathIt = defaultPaths.find(ext);
    if (pathIt != defaultPaths.end()) fullPath = pathIt->second + "/" + fileName;

    return loaderIt->second->load(fullPath);
}