#pragma once
#include "action.h"



class Wander : public Action {
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);
};