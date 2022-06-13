#ifndef GAME_H
#define GAME_H

#include <vector>
#include <fstream>
#include <string>
#include <cstdio>

#define MAX_OBJECT_ID 128
#define ANYAGE_VERSION "v0.1"

void debug(std::string message);
void print(std::string message);
std::string read(void);
int xp_to_advance(int level);

class Object {
private:
    std::string _description;
    std::string _name;
public:
    explicit Object(const std::string& name, const std::string& desc);
    explicit Object(const std::string& name);
    void setDescription(const std::string& desc);
    void setName(const std::string& name);
};

class Item : public Object {
private:
    std::string _description;
    std::string _name;
    std::string _class;
    std::string _rarity;
public:
    explicit Item(const std::string& name);
};

class Actor : public Object {
private:
    std::string _description;
    std::string _name;
    int _level, _health, _defense, _strength;
public:
    explicit Actor(const std::string& name);
    int getHP(void) const;
    void setHP(int hp);
    int getLevel(void) const;
    void attack(Actor& a);
    void die(void);
};

class Enemy : public Actor {
private:
    std::string _description;
    std::string _name;
    int _level, _health, _defense, _strength;
public:
    explicit Enemy(const std::string& name);
};

class Goblin : public Enemy {
private:
    std::string _description;
    std::string _name;
    int _level, _health, _defense, _strength;
public:
    explicit Goblin(const std::string& name);
};

class Player : public Actor {
private:
    std::string _description;
    std::string _name;
    int _level, _dexterity, _consitution, _intelligence, _wisdom, _charisma, _xp;
    int _health, _defense, _strength;
    std::vector<Item> inventory;
public:
    explicit Player(const std::string& name);
    int getXP(void) const;
    void setXP(int xp);
    int getLevel(void) const;
    void incLevel(void);
};

class Game {
public:
    Game();
    ~Game();
    void add_object(Object o);
    std::vector<Object> getItemList() const;
private:
    std::string game_title;
    std::string version;
    std::vector<Object> items_table;
};

#endif

