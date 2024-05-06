#include "pickup.h"
#include "event.h"
#include "entity.h"
#include "tile.h"
#include "engine.h"
#include "drop.h"
#include "item.h"
#include "action.h"


Pickup::Pickup(Entity& entity)
    :entity{entity} {}


void Pickup::execute(Engine& engine) {
    Vec pos = entity.get_position();
    Tile& tile = engine.dungeon.get_tile(pos);

    entity.add_to_inventory(tile.item);

    //sets item to nonexistent item so it disappears
    std::shared_ptr<Item> item;
    tile.item = item;
}

