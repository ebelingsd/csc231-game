#pragma once


#include "item.h"

class Sword_Rusty : public Item {
public:
    explicit Sword_Rusty(int damage);
    void use(Engine& engine, Entity& attack, Entity& defender) override;

private:
    int damage;
};