#include "heroes.h"
#include "action.h"
#include "engine.h"
#include "rest.h"
#include "closedoor.h"
#include "opendoor.h"
#include "sword.h"
#include "entity.h"
#include "tile.h"

namespace Heroes {
    void make_knight(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("knight");
        hero->set_max_health(20);
        hero->add_to_inventory(std::make_shared<Sword>(3));
        hero->behavior = behavior;
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        std::string key = engine.input.get_last_keypress();
        if (key == "D" || key =="Right") {
            return std::make_unique<Move>(Vec{1, 0});
        }
        else if (key == "A" || key =="Left") {
            return std::make_unique<Move>(Vec{-1, 0});
        }
        else if (key == "S" || key =="Down") {
            return std::make_unique<Move>(Vec{0, -1});
        }
        else if (key == "W" || key =="Up") {
            return std::make_unique<Move>(Vec{0, 1});
        }
        else if (key == "R" ) {
            return std::make_unique<Rest>();
        }
        else if (key =="C") {
            return std::make_unique<CloseDoor>();
        }
        else if (!key.empty() && std::isdigit(key.at(0))){
            //keys 1-5 allow you to change what you are holding (from inventory)
            int item_num = std::stoi(key) - 1;
            entity.select_item(item_num);
        }
        return nullptr;
    }
}



