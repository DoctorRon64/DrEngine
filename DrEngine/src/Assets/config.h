#pragma once
#include <string>
#include <unordered_map>

struct config {
    std::string name;
    std::unordered_map<std::string, std::string> values;
};