#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.h"

int main() {
	const std::string windowName = "DrEngine";
	bool isGamePaused = false;
	sf::Vector2u windowResolution (16 * 100, 9 * 100);

	//Window
	sf::RenderWindow* EngineWindow = new sf::RenderWindow(sf::VideoMode(windowResolution), windowName);

	//Managers
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	std::unique_ptr<RenderManager> renderManager = std::make_unique<RenderManager>();
	
	while (EngineWindow->isOpen()) {
		// ==================== Window Things =========================
		while (const std::optional event = EngineWindow->pollEvent()) {
			auto action = engine->inputManager->GetActionFromEvent(event);
			if (!action.empty()) {
				std::cout << "Action triggered: " << action << "\n";
			}

			if (event->is<sf::Event::Closed>()) {
				EngineWindow->close();
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

		engine->Update();
		renderManager->Render();

		EngineWindow->clear(sf::Color::Cyan);
		EngineWindow->display();
	}

	EngineWindow->close();
	delete(EngineWindow);
	EngineWindow = nullptr;
	
	return 0;
}