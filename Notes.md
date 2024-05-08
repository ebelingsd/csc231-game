Notes:

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



Vec  -- A 2D vector class used for position and direction
you may have to add an operator to do add and subtract, the vectors are just pairs of numbers
use get_position, move_to, +one more.


Checkpoint 1
Create Move action
    Only move Hero to an empty tile (success())
    Walls, doors, and other entities block (failure())
    Don't forget to set direction of entity
Bind Move to up/down/left/right or WASD
Bind Rest action to a key of your choice


Things to study:
pointers
constructors
futility


 Create Move action
      Only move Hero to an empty tile - done
          (success())
      Walls, doors, and other entities block - done
          (failure())
      Don't forget to set direction of entity - done
Bind Move to up/down/left/right or WASD - done
Bind Rest action to a key of your choice - done


notes for final project:

two things to do for final project, dropping loot/inventory, and create new floor

item.interact
when you call die, you would then have to call item to make it stay
you would call tile something item something
you would then have to test to see if there is an item on the place where you are standing
and if there is you would have to remove the item , and then add item to inventory
for floor it would still be item.interact and then the other function he was talking about.
then you would just call engine to create a new dungeon for you

you need to place their weapon at the place where each monster dies-done
you need to get the tile of the entity before it dies, save it, get the
weapon of the entity and save it, and then place the weapon there-done
you have to make the item be displayed-done
if there is a door it has to be beneath

tile.item.interact(pass in you and the object
in move you call pickup if tile.has_item?

