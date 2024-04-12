#pragma once
#include <memory>
#include "action.h"
#include "entity.h"
#include "move.h"

namespace Heroes {
    void make_knight(std::shared_ptr<Entity>& hero);
    std::unique_ptr<Action> behavior(Engine& engine, Entity&);
}

