#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Entity.hpp"
#include "ResourceManager.hpp"

class Engine {
public:
    Engine(const std::string& title, unsigned w, unsigned h);
    ~Engine();

    void run();

    Entity& createEntity();

    sf::RenderWindow& getWindow() { return window; }
    ResourceManager<sf::Texture>& textures() { return textureMgr; }

private:
    void processEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window;
    bool running = true;

    std::vector<std::unique_ptr<Entity>> entities;
    EntityId nextId = 1;

    // resource managers
    ResourceManager<sf::Texture> textureMgr;

    // Systems can be managed separately; for brevity we'll call render system from render()
};
