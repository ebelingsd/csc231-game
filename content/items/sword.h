#pragma once

#include "item.h"

class Sword : public Item {
public:
    explicit Sword(int damage);
    void use(Engine& engine, Entity& attack, Entity& defender) override;
    void interact(Engine& engine, Entity& entity) override;

private:
    int damage;
};