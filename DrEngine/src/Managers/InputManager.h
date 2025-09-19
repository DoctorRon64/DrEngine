#pragma once
#include <SFML/Window.hpp>
#include <unordered_map>
#include <string>
#include <functional>
#include <rapidxml.hpp>

class InputManager {
public:
    InputManager(std::shared_ptr<rapidxml::xml_document<>> config);

    void BindAction(const std::string& action, sf::Keyboard::Key key);
    void ProcessEvent(const sf::Event& event);


private:
    std::unordered_map<sf::Keyboard::Key, std::string> keyBindings;
};
