#pragma once
#include "Component.hpp"
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <vector>

using EntityId = std::uint32_t;

class Entity {
public:
    Entity(EntityId id) : id(id) {}
    EntityId getId() const { return id; }

    template<typename T, typename... Args>
    T* addComponent(Args&&... args) {
        std::type_index ti(typeid(T));
        auto comp = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = comp.get();
        components[ti] = std::move(comp);
        return ptr;
    }

    template<typename T>
    T* getComponent() {
        std::type_index ti(typeid(T));
        auto it = components.find(ti);
        if (it == components.end()) return nullptr;
        return static_cast<T*>(it->second.get());
    }

    template<typename T>
    bool hasComponent() const {
        return components.find(std::type_index(typeid(T))) != components.end();
    }

private:
    EntityId id;
    std::unordered_map<std::type_index, ComponentPtr> components;
};
