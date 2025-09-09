#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../../include/Entity.hpp"

namespace RenderSystem {
    void render(sf::RenderWindow& window, const std::vector<std::unique_ptr<Entity>>& entities);
}
