#include "sword.h"

#include "animation.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "thrust.h"
#include "sound.h"

Sword::Sword(int damage)
    :Item{"sword"}, damage{damage} {}

void Sword::use(Engine& engine, Entity& attacker, Entity& defender) {
    auto thrust = engine.events.create_event<Thrust>(sprite, attacker.get_direction());
    std::shared_ptr<Event> lightning = std::make_shared<Animation>("lightning", defender.get_position());
    lightning->add_next(Hit{defender, damage});
    engine.events.create_event<Sound>("thunder");
    thrust->add_next(lightning);     //engine.events.create_event<Hit>(defender, damage);
}
