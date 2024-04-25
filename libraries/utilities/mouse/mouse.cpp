#include <mouse/mouse.hpp>

Mouse::Mouse() {
    tip = {0, 0, 2, 2};
}

void Mouse::Update() {
    SDL_GetMouseState(&(tip.x), &(tip.y));
}

SDL_Rect* Mouse::getTip() {
    return &tip;
}