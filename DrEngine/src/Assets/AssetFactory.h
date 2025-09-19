#pragma once
#include <iostream>
#include "IAssetLoader.h"
#include <type_traits>
#include <memory>
#include <string>
#include <unordered_map>

class AssetFactory {
public:
    template<typename Loader>
    void registerLoader(const std::string& extension) {
        loaders[extension] = std::make_unique<Loader>();
    }

    IAssetLoader* getLoader(const std::string& extension) {
        auto it = loaders.find(extension);
        if (it != loaders.end()) return it->second.get(); // raw pointer
        return nullptr;
    }

    std::shared_ptr<void> request(const std::string& path) {
        // pick loader based on extension
        auto dot = path.find_last_of('.');
        std::string extension = (dot != std::string::npos) ? path.substr(dot+1) : "";

        auto file = loaders.find(extension);
        if (file == loaders.end()) {
            throw std::runtime_error("No loader registered for ." + extension);
        }
        return file->second->load(path);
    }

    template<typename T>
    std::shared_ptr<T> requestTyped(const std::string& path) {
        return std::static_pointer_cast<T>(request(path));
    }

private:
    std::unordered_map<std::string, std::unique_ptr<IAssetLoader>> loaders;
};
