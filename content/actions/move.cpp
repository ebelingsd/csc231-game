#include "move.h"
#include "engine.h"
#include "entity.h"
#include "door.h"


Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec pos = entity->get_position() + vec;
    Tile& tile = engine.dungeon.get_tile(pos);
    if (tile.is_wall() || tile.has_entity()) {
        return failure();
    }
    if (tile.has_door()) {
        tile.door->open();
        entity->change_direction(vec);
        entity->move_to(pos);
        return success();
    } else {
        entity->change_direction(vec);
        entity->move_to(pos);
    }
    return success();
}


Move::Move(Vec vec)
: vec{vec} {
}