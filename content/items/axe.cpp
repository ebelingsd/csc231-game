#include "axe.h"
#include "engine.h"
#include "hit.h"
#include "swing.h"
#include "entity.h"
#include "spin.h"


Axe::Axe(int damage)
    :Item{"axe"}, damage{damage} {}

void Axe::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Spin>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}