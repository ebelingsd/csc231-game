#include "drop.h"
#include "event.h"
#include "action.h"
#include "tile.h"
#include "engine.h"
#include "entity.h"


Drop::Drop(Entity& entity)
    :entity{entity} {}


void Drop::execute(Engine& engine) {
    //save position of monster that died
    Vec pos = entity.get_position();
    Tile& tile = engine.dungeon.get_tile(pos);
    //gets item of the monster that died
    tile.item = entity.get_current_item();
}
