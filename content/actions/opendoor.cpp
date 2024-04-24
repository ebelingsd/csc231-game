#include "opendoor.h"

#include "door.h"
#include "engine.h"
#include "updatefov.h"



Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) { //maybe change it to door??    or recreate the constructor
    door.open();
    engine.events.create_event<UpdateFOV>();
    return success();
}


OpenDoor::OpenDoor(Door& door)
    :door{door} {}

