#pragma once
#include "ECS/entity.h"
#include "Assets/XmlLoader.h"
#include "Assets/SpriteLoader.h"
#include "Managers/EntityManager.h"
#include "Managers/AssetManager.h"
#include "Managers/RenderManager.h"
#include "Managers/InputManager.h"
#include <rapidxml.hpp>
#include <iostream>
#include <memory>

class Engine {
    private:
        std::shared_ptr<EntityManager> entityManager;
        std::shared_ptr<AssetManager> assetManager;
    public:
	    std::shared_ptr<InputManager> inputManager;
        Engine();
        ~Engine();
        void Update();
};