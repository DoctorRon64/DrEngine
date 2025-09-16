#pragma once
#include <cstdint>
#include <iostream>

class Entity {
    public:
        Entity() : id(nextId++) {
            printf("New Entity Created with id: %u\n", id);
        }
        
        std::uint32_t getId() const {
            printf("The Entity id is: %u\n", id);
            return id; 
        }

    private:
        std::uint32_t id;
        inline static std::uint32_t nextId = 0;
};