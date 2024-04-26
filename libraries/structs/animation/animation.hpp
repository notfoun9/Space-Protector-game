#pragma once

#include<game/game.hpp>

struct Animation {
    Animation() = default;
    Animation(int i, int f, int s) : index(i), frames(f), speed(s) {}
    ~Animation() = default;

    int index;
    int frames;
    int speed;
} ;