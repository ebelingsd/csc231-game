#pragma once

#include "item.h"

class Sword : public Item {
public:
    explicit Sword(int damage);
    void use(Engine& engine, Entity& attack, Entity& defender) override;

private:
    int damage;
};