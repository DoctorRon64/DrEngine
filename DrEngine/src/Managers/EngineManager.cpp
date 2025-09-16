#include "EngineManager.h"
#include "ECS/entity.h"
#include <iostream>

EngineManager::EngineManager() {
    entityManager = std::make_shared<EntityManager>();

    std::shared_ptr<Entity> player = entityManager->createEntity();
}

EngineManager::~EngineManager() {

}

void EngineManager::Update() {

}