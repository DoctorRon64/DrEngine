#pragma once
#include <cstdint>
#include <iostream>

class Entity {
public:
    Entity() : id(generateId()) {
        std::cout << "New Entity Created with id: " << id << std::endl;
    }

    std::uint32_t getId() const {
        return id;
    }

private:
    static std::uint32_t nextId; // Declaration only
    std::uint32_t id;

    static std::uint32_t generateId() {
        return nextId++;
    }
};