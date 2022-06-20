#pragma once

#include <string>

class Object {
protected:
    std::string _description;
    std::string _name;
public:
    Object(const std::string& name, const std::string& desc);
    explicit Object(const std::string& name);
    void setDescription(const std::string& desc);
    void setName(const std::string& name);
};

