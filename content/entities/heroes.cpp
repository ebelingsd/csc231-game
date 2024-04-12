#include "heroes.h"

#include "action.h"
#include "rest.h"

namespace Heroes {
    void make_knight(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("knight");
        hero->set_max_health(10);
        hero->behavior = behavior;
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
        std::string key = engine.input.get_last_keypress();
        if (key == "D") {
            return std::make_unique<Move>(Vec{1, 0});
        }
        else if (key == "A") {
            return std::make_unique<Move>(Vec{-1, 0});
        }
        else if (key == "S") {
            return std::make_unique<Move>(Vec{0, -1});
        }
        else if (key == "W") {
            return std::make_unique<Move>(Vec{0, 1});
        }
        else if (key == "R") {
            return std::make_unique<Rest>();
        }
        return nullptr;
    }
}




//// do i need this, i feel like what i did above works but is this also needed??
//Move::Action
//Result perform(engine, entity)
//entity->move_to(get_pos()+direction)
//
////where do I put this? if anywhere?
//Vec position{10, 10}; // (x, y)
//Vec direction{1, 0}; // right
//Vec new_position = position + direction; // (11, 10)
//// OR
//Vec old_pos{2, 3}, new_pos{3, 3};
//Vec direction = new_pos - old_position; // (1, 0)
//
//
////am i supposed to do anything with this?
//Vec position{1, 2};
//Tile& tile = engine.dungeon.get_tile(position);
//// do things with tile
//
////these are the main functions that you have to use, question is how do you use them in the thing above
//Vec get_position() const;
//void move_to(Vec position);
//void change_direction(Vec direction);
//
//Vec operator+(const Vec& a, const Vec& b);
//Vec operator-(const Vec& a, const Vec& b);
//
////how to implement taking turns
//std::unique_ptr<Action> Entity::take_turn() {
//    if (behavior) {
//        return behavior(engine, *this);
//    }
//    return nullptr;
//}

// Create Move action
//      Only move Hero to an empty tile - done
//          (success())
//      Walls, doors, and other entities block - done
//          (failure())
//      Don't forget to set direction of entity - done
// Bind Move to up/down/left/right or WASD - done
// Bind Rest action to a key of your choice - done