#pragma once
#include <SFML/Window.hpp>
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <rapidxml.hpp>

class InputManager {
public:
    InputManager(std::shared_ptr<rapidxml::xml_document<>> config);

private:
    std::unordered_map<sf::Keyboard::Key, std::string> keyBindings;
};