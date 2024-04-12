#pragma once
#include "engine.h"
#include "action.h"
#include "entity.h"
#include "vec.h"


class Move : public Action {
public:
    Move(Vec vec);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
//    std::unique_ptr<Action> behavior(Engine& engine, Entity&);
    std::unique_ptr<Action> move;
private:
    Vec vec;
};


