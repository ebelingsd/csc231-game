//
// Created by Silas Ebeling on 4/23/24.
//

#include "sword_rusty.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"


Sword_Rusty::Sword_Rusty(int damage)
    :Item{"sword_rusty"}, damage{damage} {}

void Sword_Rusty::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}