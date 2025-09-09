#include "RenderSystem.hpp"
#include "../../include/Components/Transform.hpp"
#include "../../include/Components/SpriteComp.hpp"

namespace RenderSystem {
    void render(sf::RenderWindow& window, const std::vector<std::unique_ptr<Entity>>& entities) {
        for (const auto& ePtr : entities) {
            if (!ePtr) continue;
            Entity* e = ePtr.get();
            if (e->hasComponent<Transform>() && e->hasComponent<SpriteComp>()) {
                auto t = e->getComponent<Transform>();
                auto sc = e->getComponent<SpriteComp>();
                if (!sc) continue;
                sc->sprite.setPosition(t->position);
                sc->sprite.setRotation(t->rotation);
                sc->sprite.setScale(t->scale);
                window.draw(sc->sprite);
            }
        }
    }
}

