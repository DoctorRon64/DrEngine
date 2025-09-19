#pragma once
#include <memory>
#include <string>

class IAssetLoader {
public:
    virtual ~IAssetLoader() = default;
    virtual std::shared_ptr<void> load(const std::string& path) = 0;
};
