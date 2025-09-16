#pragma once
#include <SFML/Graphics.hpp>

// -------------------- Components -------------------- //
struct Position {
    float x, y;
};

struct Scale {
    float width, height;
};

struct Sprite {
    sf::Sprite sprite;
};

struct Velocity {
    float dx, dy;
};
