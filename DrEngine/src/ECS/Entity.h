#pragma once
#include <cstdint>
#include <iostream>

class Entity {
public:
    explicit Entity(std::uint32_t newId) : id(newId) {
        std::cout << "New Entity Created with id: " << id << std::endl;
    }

    std::uint32_t getId() const {
        return id;
    }

private:
    std::uint32_t id;
};