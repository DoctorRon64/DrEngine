#include "Engine.hpp"
#include "Systems/RenderSystem.hpp"
#include <iostream>

Engine::Engine(const std::string& title, unsigned w, unsigned h)
    : window(sf::VideoMode(sf::Vector2u(w, h)), title)
{
    window.setVerticalSyncEnabled(true);
}

Engine::~Engine() = default;

Entity& Engine::createEntity() {
    auto e = std::make_unique<Entity>(nextId++);
    Entity& ref = *e;
    entities.push_back(std::move(e));
    return ref;
}

void Engine::processEvents() {
    sf::Event ev(window);
    while (window.pollEvent(ev)) {
        if (ev.is<sf::Event::Closed>()) {
            running = false;
        }
    }
}

void Engine::update(float dt) {
    // update systems (physics, AI, etc.) - omitted for brevity
    // For a bigger engine, call registered systems here.
    (void)dt;
}

void Engine::render() {
    window.clear(sf::Color::Black);

    // Simple render: use RenderSystem helper to draw entities with SpriteComp+Transform
    RenderSystem::render(window, entities);

    window.display();
}

void Engine::run() {
    const float TIME_STEP = 1.0f / 60.0f;
    float accumulator = 0.f;
    sf::Clock clock;

    while (running && window.isOpen()) {
        processEvents();

        float frameTime = clock.restart().asSeconds();
        if (frameTime > 0.25f) frameTime = 0.25f; // avoid spiral of death
        accumulator += frameTime;

        while (accumulator >= TIME_STEP) {
            update(TIME_STEP);
            accumulator -= TIME_STEP;
        }

        render();
    }
}
