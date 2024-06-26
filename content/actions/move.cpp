#include "move.h"
#include "engine.h"
#include "entity.h"
#include "door.h"
#include "opendoor.h"
#include "rest.h"
#include "attack.h"
#include "item.h"


Move::Move(Vec vec)
    : vec{vec} {
}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec pos = entity->get_position() + vec;
    Tile& tile = engine.dungeon.get_tile(pos);
    entity->change_direction(vec);
    if (tile.is_wall()) {
        return failure();
    }
    if (tile.has_door() && !tile.door->is_open()) {
        return alternative(OpenDoor{*tile.door});
    }
   if (tile.has_entity()) {
        if (entity->get_team() != tile.entity->get_team()) {
            return alternative(Attack{*tile.entity});
        }
        else {
            return alternative(Rest{});
        }
    }

    else {
        //must be an empty walkable tile
        entity->move_to(pos);
        //if hero walks onto tile with an item, it gets added to inventory
        if (tile.has_item() && entity == engine.hero) {
            tile.item->interact(engine, *entity);
        }
    }
    return success();
}


