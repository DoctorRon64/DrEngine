#include "EntityManager.h"

EntityManager::EntityManager(std::uint32_t newMaxEntities) : maxEntities() {
    //pre-allocate entity slots
    maxEntities = newMaxEntities;
    availableEntities.reserve(maxEntities);
}

std::shared_ptr<Entity> EntityManager::createEntity() {
    if (availableEntities.size() >= maxEntities) {
        throw std::runtime_error("No more entity slots available!");
    }

    std::shared_ptr<Entity> entity = std::make_shared<Entity>();
    availableEntities.push_back(entity);

    return entity;
}

void EntityManager::destroyEntity(const std::shared_ptr<Entity>& entity) {
    auto selectedEntity = std::remove(availableEntities.begin(), availableEntities.end(), entity);

    if (selectedEntity != availableEntities.end()) {
        availableEntities.erase(selectedEntity, availableEntities.end());
    }
}