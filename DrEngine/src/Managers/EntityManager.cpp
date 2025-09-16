#include "EntityManager.h"
#include "ECS/Entity.h"
#include <iostream>
#include <cstdint>

EntityManager::EntityManager(std::uint32_t newMaxEntities) {
    maxEntities = newMaxEntities;
    for (std::uint32_t i = 0; i < maxEntities; i++) {
        availableEntities.push(i);
    }
    
}

EntityManager::~EntityManager() {

}

std::uint32_t EntityManager::createEntity() {
    if (availableEntities.empty()) {
        return UINT32_MAX;
    }
    std::uint32_t id = availableEntities.front();
    availableEntities.pop();
    return id;
}

void EntityManager::destroyEntity(std::uint32_t id){
    availableEntities.push(id);
}