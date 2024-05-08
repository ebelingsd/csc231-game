#include "sword_rusty.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"
#include "pickup.h"


Sword_Rusty::Sword_Rusty(int damage)
    :Item{"sword_rusty"}, damage{damage} {}

void Sword_Rusty::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}
void Sword_Rusty::interact(Engine& engine, Entity& entity) {
    //picks up rusty sword
    engine.events.create_event<Pickup>(entity);
}
