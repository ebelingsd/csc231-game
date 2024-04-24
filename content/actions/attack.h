#pragma once
#include "entity.h"
#include "action.h"


// content/actions/attack.h
class Attack : public Action {
public:
    Attack(Entity& defender);
    // use current item on defender
    Result perform(Engine& engine, std::shared_ptr<Entity> attacker);
    std::shared_ptr<Item> get_current_item() const;

private:
    Entity& defender;
};
