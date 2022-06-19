#include "object.hpp"

#include <string>

Object::Object(const std::string& name, const std::string& desc)
: _name(name), _description(desc)
{
}

Object::Object(const std::string& name)
: _name(name), _description("")
{
}

void Object::setDescription(const std::string& desc) {
    _description = desc;
}

void Object::setName(const std::string& name) {
    _name = name;
}

