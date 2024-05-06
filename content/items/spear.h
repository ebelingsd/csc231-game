#pragma once
#include "tile.h"

#include "item.h"

class Spear : public Item {
public:
    explicit Spear(int damage);
    void use(Engine& engine, Entity& attack, Entity& defender) override;
    void interact(Engine& engine, Entity& entity) override;

private:
    int damage;
};