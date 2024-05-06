#pragma once
#include "event.h"
#include "item.h"

class Drop : public Event {
public:
    Drop(Entity& entity);
    void execute(Engine& engine);

private:
    Entity& entity;
};