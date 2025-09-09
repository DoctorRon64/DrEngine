#include "Engine.hpp"
#include "Components/Transform.hpp"
#include "Components/SpriteComp.hpp"
#include <iostream>

int main() {
    Engine engine("MySFMLEngine", 960, 540);

    // load textures
    auto tex = engine.textures().load("player", "assets/sprites/player.png");
    if (!tex) {
        std::cerr << "Failed to load player texture\n";
        return 1;
    }

    // create a player entity
    Entity& player = engine.createEntity();
    auto* t = player.addComponent<Transform>();
    t->position = { 400.f, 200.f };

    auto* sc = player.addComponent<SpriteComp>();
    sc->sprite.setTexture(*tex);
    sc->sprite.setOrigin(tex->getSize().x / 2.f, tex->getSize().y / 2.f);

    // create more entities...
    engine.run();

    return 0;
}
