#include "EntityManager.h"
#include <memory>

EntityManager::EntityManager(std::uint32_t newMaxEntities) : maxEntities(newMaxEntities) {
}

std::shared_ptr<Entity> EntityManager::createEntity() {
    if (availableEntities.empty()) {
        throw std::runtime_error("No more entity IDs available!");
    }

    std::shared_ptr<Entity> entity = std::make_shared<Entity>();
    availableEntities.push(entity); //TODO 

    return entity;
}

void EntityManager::destroyEntity(std::shared_ptr<Entity> entity) {
    availableEntities.pop(entity); //TODO
    std::cout << "Entity Destroyed with id: " << entity->getId() << std::endl;
}