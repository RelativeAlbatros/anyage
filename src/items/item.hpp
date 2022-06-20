#pragma once

#include "../object.hpp"
#include <string>

class Item : public Object {
protected:
    std::string _class;
    std::string _rarity;
public:
    explicit Item(const std::string& name);
};

