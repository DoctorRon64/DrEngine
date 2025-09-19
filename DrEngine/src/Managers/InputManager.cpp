#include "InputManager.h"

void InputManager::BindAction(const std::string& action, sf::Keyboard::Key key) {
    keyBindings[key] = action;

    
}

void InputManager::ProcessEvent(const sf::Event& event) {

}
