#include "EngineManager.h"
#include "ECS/entity.h"
#include <iostream>

EngineManager::EngineManager() {
    entityManager = std::make_shared<EntityManager>(maxEntities);

    std::shared_ptr<Entity> player = entityManager->createEntity();
    std::shared_ptr<Entity> Enemy = entityManager->createEntity();
    std::shared_ptr<Entity> Villager = entityManager->createEntity();
    std::shared_ptr<Entity> NPC = entityManager->createEntity();
    std::shared_ptr<Entity> oBAMA = entityManager->createEntity();
    std::shared_ptr<Entity> Paco = entityManager->createEntity();
}

EngineManager::~EngineManager() {

}

void EngineManager::Update() {

}