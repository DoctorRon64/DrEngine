#pragma once
#include "../Component.hpp"
#include <SFML/System.hpp>

struct Transform : public Component {
    sf::Vector2f position{ 0.f,0.f };
    float rotation = 0.f;
    sf::Vector2f scale{ 1.f,1.f };
};
