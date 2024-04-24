#include "attack.h"
#include "hit.h"
#include "item.h"
#include "entity.h"

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    attacker->get_current_item()->use(engine, *attacker, defender);
    return success();
}

Attack::Attack(Entity& defender)
    : defender{defender} {
}