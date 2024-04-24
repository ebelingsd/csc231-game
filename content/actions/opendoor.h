#pragma once
#include "action.h"
#include "door.h"

class OpenDoor : public Action {
public:
    OpenDoor(Door& door);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

private:
    Door& door;
};