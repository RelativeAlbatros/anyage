#ifndef GAME_H
#define GAME_H

#include <vector>
#include <fstream>
#include <string>
#include <cstdio>

#define MAX_OBJECT_ID 128
#define ANYAGE_VERSION "v0.1"

void debug(const std::string& message);
void print(std::string message);
std::string read(void);
int xp_to_advance(int level);

class Object {
protected:
    std::string _description;
    std::string _name;
public:
    explicit Object(const std::string& name, const std::string& desc);
    explicit Object(const std::string& name);
    void setDescription(const std::string& desc);
    void setName(const std::string& name);
};

class Item : public Object {
protected:
    std::string _class;
    std::string _rarity;
public:
    explicit Item(const std::string& name);
};

class Actor : public Object {
protected:
    int _level, _health, _power;
public:
    Actor(const std::string& name, const int level, const int max_hp, const int power);
    std::string getName(void) const;
    virtual int calculateMaxHealth(const int level) const = 0;
    virtual int calculateAttack(const int level) const = 0;
    virtual int getDamage(const int level) const = 0;
    int getHP(void) const;
    void setHP(int hp);
    int getLevel(void) const;
    virtual void attack(Actor& a);
    void die(void);
};

/* class Enemy : public Actor { */
/* public: */
/*     Enemy(const std::string& name, const int level); */
/* }; */

class Goblin : public Actor {
public:
    Goblin(const std::string& name, const int level);
    int calculateMaxHealth(const int level) const override;
    int calculateAttack(const int level) const override;
    int getDamage(const int level) const override;
    void attack(Actor& target) override;
};

class Player : public Actor {
private:
    int _xp;
    int _strength, _attack;
    std::vector<Item> inventory;
public:
    Player(const std::string& name, const int level, const int xp);
    int calculateMaxHealth(const int level) const override;
    int calculateAttack(const int level) const override;
    int getDamage(const int level) const override;
    int getXP(void) const;
    void setXP(int xp);
    int getLevel(void) const;
    void incLevel(void);
    void attack(Actor& target) override;
};

class Game {
public:
    Game(const std::string& name);
    ~Game();
    void add_object(Object o);
    std::vector<Object> getItemList() const;
private:
    std::string game_title;
    std::vector<Object> items_table;
};

#endif

