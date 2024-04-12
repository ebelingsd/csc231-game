
read a lot from engine.h
make sure to draw lots of pictures to figure out the chain of logic
read mostly .h files to know what functions you need to use
you're gonna write 500-1000 lines of code by the end of the semester

Move:Action
Result perform (eng,ent)
ent->move_to(get_pos()+direction)

Tile-based -- entities can only exist at integer positions (x, y)
Turn-based -- each entity takes a turn, then waits for others
Entities-Actions -- Engine processes actions (move, attack) that entities create
Events -- results of actions (hit, animation)

you define your own characters, weapons
you write your own actions/moves
entity produces actions triggers events
    

do not produce Results directly, use helper functions!  
like success()  action worked, entity finihsed with turn 
failure() couldn't perform action, give entity another turn
alternative(anotherAction{}) couldn't perform action, do this one instead, anotherACtion, fill it in with the action yyou want to do, not actually anotheraction{}
result always returns one of those three functions
if someone cannot make a move, use return alternative(rest{})
just call member functions and say whether success or failure


may need to use this for one of your entities
    std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
    std::string key = engine.input.get_last_keypress();
    if (key == "Right" || key == "D") {
    return std::make_unique<Move>(Vec{1, 0});
    }
    ...
    else if (key == "C") {
    return std::make_unique<CloseDoor>();
    }
    return nullptr;
    }

Vec  -- A 2D vector class used for position and direction
you may have to add an operator to do add and subtract, the vectors are just pairs of numbers
use get_position, move_to, +one more.?.

Vec position{1, 2};
Tile& tile = engine.dungeon.get_tile(position);
//do things with tile (make sure to use & to make a copy)


you need to be able to push a key wait what
create key bindings for arrows, 


Checkpoint 1
Create Move action
    Only move Hero to an empty tile (success())
    Walls, doors, and other entities block (failure())
    Don't forget to set direction of entity
Bind Move to up/down/left/right or WASD
Bind Rest action to a key of your choice
LIKELY USE SOME OF THE CODE THAT HE GAVE US IN THE SLIDES RIGHT ABOVE THE ASSIGNMENT
std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
std::string key = engine.input.get_last_keypress();
if (key == "Right") {
return std::make_unique<Move>(Vec{1, 0});
}
else if (key == "F") {
return std::make_unique<ThrowFire>();
}
return nullptr;
}

and
Vec pos{1, 1};
Tile& tile = engine.dungeon.get_tile(pos);
if (tile.is_wall() || tile.has_entity()) {
// cannot move there
}
if (tile.has_door()) {
// do something with door
}

and
Vec position{10, 10}; // (x, y)
Vec direction{1, 0}; // right
Vec new_position = position + direction; // (11, 10)
// OR
Vec old_pos{2, 3}, new_pos{3, 3};
Vec direction = new_pos - old_position; // (1, 0)

and


maybe
Vec position{1, 2};
Tile& tile = engine.dungeon.get_tile(position);
// do things with tile

maybe
Vec operator+(const Vec& a, const Vec& b);
Vec operator-(const Vec& a, const Vec& b);


use these functions from entity
// engine/entity.h
class Entity {
public:
Vec get_position() const;
void move_to(Vec position);
void change_direction(Vec direction);
};



Things to study:
pointers
constructors
futility


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

Solutions to bugs I fixed:
