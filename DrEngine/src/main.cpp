#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Managers/EngineManager.h"
#include "Managers/RenderManager.h"
#include "Managers/EntityManager.h"

int main() {
	const std::string windowName = "DrEngine";
	sf::Vector2u windowResolution (16 * 100, 9 * 100);
	bool isGamePaused = false;

	sf::RenderWindow EngineWindow;
	EngineWindow.create(sf::VideoMode(windowResolution), windowName);

	EngineManager manager;
	RenderManager renderer;
	EntityManager entityManager(20);
	//InputManager

	std::uint32_t player = entityManager.createEntity();
	printf("%n\n", player);

	entityManager.destroyEntity(player);
	printf("%n\n", player);
	

	while (EngineWindow.isOpen()) {
		// ==================== Window Things =========================
		while (const std::optional event = EngineWindow.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				EngineWindow.close();
			}

			if (event->is<sf::Event::FocusLost>())
				isGamePaused = true;

			if (event->is<sf::Event::FocusGained>())
				isGamePaused = false;

			else if (const auto* resized = event->getIf<sf::Event::Resized>()) {
				float newSizeX = resized->size.x;
				float newSizeY = resized->size.y;
				
				windowResolution.x = newSizeX;
				windowResolution.y = newSizeY;
			}
		}

		// ============== Game Loop ==================
		//Process Input
		manager.Update();
		renderer.Render();

		EngineWindow.clear(sf::Color::Cyan);
		EngineWindow.display();
	}

	EngineWindow.close();
	return 0;
}