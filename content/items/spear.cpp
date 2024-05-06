#include "spear.h"


#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "pickup.h"
#include "thrust.h"

Spear::Spear(int damage)
    :Item{"spear"}, damage{damage} {}

void Spear::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}

void Spear::interact(Engine& engine, Entity& entity) {
    engine.events.create_event<Pickup>(entity);
}
