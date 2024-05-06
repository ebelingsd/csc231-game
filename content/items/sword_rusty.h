#pragma once


#include "item.h"

class Sword_Rusty : public Item {
public:
    explicit Sword_Rusty(int damage);
    void use(Engine& engine, Entity& attack, Entity& defender) override;
    void interact(Engine& engine, Entity& entity) override;

private:
    int damage;
};