#pragma once

#include "item.h"

class Axe : public Item {
public:
    explicit Axe(int damage);
    void use(Engine& engine, Entity& attack, Entity& defender) override;

private:
    int damage;
};