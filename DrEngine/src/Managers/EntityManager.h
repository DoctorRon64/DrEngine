#pragma once
#include <queue>
#include <cstdint>

class EntityManager {
private:
    std::queue<std::uint32_t> availableEntities;
    std::uint32_t maxEntities;

public:
    EntityManager(std::uint32_t max = 5000);
    ~EntityManager();

    std::uint32_t createEntity();
    void destroyEntity(std::uint32_t id);
};
