#include <mouse/mouse.hpp>
#include <utilities/utilities.hpp>

Mouse::Mouse(std::string str) {
    tex = TextureManager::LoadTexture(str.data());
    tip = {0, 0, 2, 2};
}

void Mouse::Update() {
    SDL_GetMouseState(&(destFRect.x), &(destFRect.y));
    SDL_GetMouseState(&(tip.x), &(tip.y));

    destFRect.x -= 23;
    destFRect.y -= 23;
    tip.x -= 22;
    tip.y -= 22;
}

SDL_FRect* Mouse::getTip() {
    return &tip;
}
