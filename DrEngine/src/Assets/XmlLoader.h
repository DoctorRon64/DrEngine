#pragma once
#include <memory>
#include "IAssetLoader.h"
#include "config.h"

class XmlLoader : public IAssetLoader {
public:
    std::shared_ptr<void> load(const std::string& path) override {
        auto cfg = std::make_shared<config>();
        return cfg;
    }
};
