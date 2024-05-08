#pragma once
#include "event.h"
#include "item.h"
#include "tile.h"

class Pickup : public Event {
public:
    Pickup(Entity& entity);
    void execute(Engine& engine) override;

private:
    Entity& entity;
};


