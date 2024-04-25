#pragma once

#include <game/game.hpp>

class Mouse {
public:
    Mouse();
    ~Mouse() = default;

    void Update();
    // void Render();

    SDL_Rect* getTip();
private:
    // SDL_Rect cursor;
    SDL_Rect tip;

    // SDL_Texture* mouseTex;
} ; 