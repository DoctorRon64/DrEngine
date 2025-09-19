#pragma once
#include "EntityManager.h"
#include "ECS/entity.h"
#include "AssetManager.h"
#include "Assets/XmlLoader.h"
#include "Assets/SpriteLoader.h"

#include <iostream>
#include <memory>

class EngineManager {
    private:
        std::shared_ptr<EntityManager> entityManager;
        std::shared_ptr<AssetManager> assetManager;
        int maxEntities = 200;

    public:
        EngineManager();
        ~EngineManager();
        void Update();
};