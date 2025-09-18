#pragma once
#include "EntityManager.h"
#include <memory>

class EngineManager {
    private:
        std::shared_ptr<EntityManager> entityManager;
        int maxEntities = 200;

    public:
        EngineManager();
        ~EngineManager();
        void Update();
};