#pragma once
#include "EntityManager.h"
#include <memory>

class EngineManager {
    private:
        std::shared_ptr<EntityManager> entityManager;

    public:
        EngineManager();
        ~EngineManager();
        void Update();
};