#include "monsters.h"
#include "action.h"
#include "engine.h"
#include "rest.h"
#include "sword.h"
#include "entity.h"
#include "randomness.h"
#include "monsters.h"
#include "engine.h"
#include "wander.h"
#include "move.h"
#include "sword_rusty.h"
#include "spear.h"
#include "axe.h"
#include "tile.h"

namespace Monsters {
void make_ogre(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("ogre");
    monster->set_max_health(6);
    monster->add_to_inventory(std::make_shared<Sword_Rusty>(4));
    monster->behavior = behavior;
}

void make_orc_masked(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("orc_masked");
    monster->set_max_health(3);
    monster->add_to_inventory(std::make_shared<Axe>(3));
    monster->behavior = behavior;
}

void make_goblin(std::shared_ptr<Entity>& monster) {
    monster->set_sprite("goblin");
    monster->set_max_health(3);
    monster->add_to_inventory(std::make_shared<Spear>(3));
    monster->behavior = behavior;
}

std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
    // pursue Hero if monster can see him (If Hero sees me, I see him)
    if (entity.is_visible() && engine.hero) {
        auto path = engine.dungeon.calculate_path(entity.get_position(),
                                                  engine.hero->get_position());
        if (path.size() > 1) {
            auto direction = path.at(1) - path.at(0);
            if (probability(17)) {
                return std::make_unique<Rest>();
            }
            return std::make_unique<Move>(direction);

        }
    }
    // Monster doesn't see Hero
    if (probability(66)) {
        return std::make_unique<Wander>();
    }
    else {
        return std::make_unique<Rest>();
    }
}
}
