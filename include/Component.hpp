#pragma once
#include <typeindex>
#include <memory>

struct Component {
    virtual ~Component() = default;
};
using ComponentPtr = std::unique_ptr<Component>;
