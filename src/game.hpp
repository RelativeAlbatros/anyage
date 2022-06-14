#ifndef GAME_H
#define GAME_H

#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <ncurses.h>

/* macros */
#define ANYAGE_VERSION "v0.11"

/* classes */
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
    int _level, _health, _attack;
public:
    Actor(const std::string& name, const int level, const int max_hp, const int attack);
    std::string getName(void) const;
    virtual int calculateMaxHealth(const int level) const = 0;
    virtual int calculateAttack(const int level) const = 0;
    virtual int getDamage(const int level) const = 0;
    int getHP(void) const;
    void setHP(int hp);
    int getLevel(void) const;
    virtual std::string attack(Actor& a);
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
    std::string attack(Actor& target) override;
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
    int xp_to_advance(const int level) const;
    int getXP(void) const;
    void setXP(int xp);
    int getLevel(void) const;
    void incLevel(void);
    std::string attack(Actor& target) override;
};

class Game {
public:
    explicit Game(const std::string& name);
    ~Game();
    void tick(void);
    void add_object(Object o);
    std::vector<Object> getItemList() const;

    friend void print_to_log(Game& g, const std::string& message);
private:
    WINDOW *world_window;
    WINDOW *log_window;
    std::string game_title;
    std::vector<Object> items_table;
};

/* functions */
void debug(const std::string& message);
void print_to_log(Game& g, const std::string& message);
std::string read(void);

#endif
