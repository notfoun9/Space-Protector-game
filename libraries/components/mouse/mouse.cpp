#include <mouse/mouse.hpp>
#include <utilities/utilities.hpp>

Mouse::Mouse(std::string str) {
    tex = TextureManager::LoadTexture(str.data());
    tip = {0, 0, 2, 2};
}

void Mouse::Update() {
    SDL_GetMouseState(&(destRect.x), &(destRect.y));
    SDL_GetMouseState(&(tip.x), &(tip.y));

    destRect.x -= 20;
    destRect.y -= 20;
    tip.x -= 22;
    tip.y -= 22;
}

SDL_Rect* Mouse::getTip() {
    return &tip;
}