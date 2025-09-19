#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IAssetloader.h"

class SpriteLoader : public IAssetLoader {
    public:
    std::shared_ptr<void> load(const std::string& path) override {
        auto texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(path)) {
            throw std::runtime_error("Failed to load texture: " + path);
        }
        return texture;
    }
};
