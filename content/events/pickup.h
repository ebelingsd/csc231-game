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

//tile.item.interact(pass in you and the object
//in move you call pickup if tile.has_item?
