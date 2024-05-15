#pragma once

#include <game/game.hpp>

class FPSController {
public:
    FPSController() noexcept;
    ~FPSController() noexcept;
private:
    const int FPS = 90;
    const int frameDelay = 1000 / FPS;
    uint32_t frameStart = 0;
    int frameTime = 0;
} ;