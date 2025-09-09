#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>
#include <cassert>

template<typename Resource>
class ResourceManager {
public:
    ResourceManager() = default;

    Resource* load(const std::string& id, const std::string& filepath) {
        auto it = resources.find(id);
        if (it != resources.end()) return it->second.get();

        auto res = std::make_unique<Resource>();
        if constexpr (std::is_same<Resource, sf::Texture>::value) {
            if (!res->loadFromFile(filepath)) return nullptr;
        }
        else {
            // could expand for other resource types
            (void)filepath;
        }

        Resource* ptr = res.get();
        resources[id] = std::move(res);
        return ptr;
    }

    Resource* get(const std::string& id) {
        auto it = resources.find(id);
        return it == resources.end() ? nullptr : it->second.get();
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Resource>> resources;
};
