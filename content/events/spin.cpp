#include "spin.h"
#include <cmath>

constexpr int duration = 10;

Spin::Spin(Sprite& sprite, Vec direction)
    :Event{duration}, sprite{sprite}, copy{sprite}, starting_angle{sprite.angle} {
    if (direction == Vec{1, 0}) {
        starting_angle = 0;
        delta = 360 / (duration - 1);
    }
    else if (direction == Vec{-1, 0}) {
        starting_angle = 0;
        delta = -360 / (duration - 1);
    }
    else if (direction == Vec{0, 1}) {
        sprite.shift.y -= 12;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = -75 * sign;
        delta = 360 / (duration - 1) * sign;
    }
    else {
        sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 135 * sign;
        delta = 360 / (duration - 1) * sign;
    }
}

void Spin::execute(Engine&) {
    sprite.angle = starting_angle + delta * frame_count;
}

void Spin::when_done(Engine&) {
    sprite = copy;
}