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
//you need to place their weapon at the place where each monster dies-done
//you need to get the tile of the entity before it dies, save it, get the
    // weapon of the entity and save it, and then place the weapon there-done
//you have to make the item be displayed-done
    //if there is a door it has to be beneath
