#include "die.h"
#include "engine.h"
#include "entity.h"
#include "drop.h"


Die::Die(Entity& entity)
    :entity{entity} {}

void Die::execute(Engine& engine) {
    engine.remove_entity(entity);
    //drops the weapon when the monster dies
    engine.events.create_event<Drop>(entity);
}

