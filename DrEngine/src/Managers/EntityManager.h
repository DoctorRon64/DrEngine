#pragma once
#include <queue>
#include <cstdint>
#include <memory>
#include <algorithm>
#include "ECS/Entity.h"

class EntityManager {
private:
    std::vector<std::shared_ptr<Entity>> availableEntities;
    std::uint32_t maxEntities;
public:
    EntityManager(std::uint32_t newMaxEntities);
    ~EntityManager() = default;

    std::shared_ptr<Entity> createEntity();
    void destroyEntity(const std::shared_ptr<Entity>& entity);
};
