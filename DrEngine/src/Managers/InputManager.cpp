#include "InputManager.h"
#include <rapidxml.hpp>
#include <rapidxml_iterators.hpp>

void InputManager::BindAction(const std::string& action, sf::Keyboard::Key key) {
    keyBindings[key] = action;

    
}

void InputManager::ProcessEvent(const sf::Event& event) {

}
