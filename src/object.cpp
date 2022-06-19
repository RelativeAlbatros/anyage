#include "object.hpp"

#include <string>

Object::Object(Game& g, const std::string& name, const std::string& desc)
: _name(name), _description(desc)
{
    g.add_object(this);
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

