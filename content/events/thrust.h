#pragma once
#include "sprite.h"
#include "event.h"

class Thrust : public Event {
public:
    Thrust(Sprite& sprite, Vec direction);


    //execute: sprite.shift +=
    void execute(Engine& engine) override;

    void when_done(Engine& engine) override;

private:
    Sprite& sprite; //original weapon sprite
    Sprite copy; //copy so that we can reset it after animation
    Vec direction; //which direction to shift

};