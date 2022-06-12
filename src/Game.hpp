#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#define MAX_OBJECT_ID 128

class Object {
private:
  std::string _description;
  std::string _name;
public:
    explicit Object(const std::string& name, const std::string& desc);
    explicit Object(const std::string& name);
};

class Game {
public:
    Game();
    ~Game();
    void add_object(Object o);
    std::vector<Object> getItemList() const;
private:
    std::vector<Object> items_table;
    friend class Object;
};

/* class Actor : public Object { */
/* private: */
/*   int _health; */
/*   int _power; */
/* public: */
/*   Actor(); */
/* }; */


#endif
