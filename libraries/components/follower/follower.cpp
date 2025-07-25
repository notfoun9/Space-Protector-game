#include <follower/follower.hpp>
#include <texture_manager/texture_manager.hpp>

Follower::Follower(std::string texture) {
    tex = TextureManager::LoadTexture(texture.data());
}

void Follower::SetCenter(float x, float y) {
    center = {x,y};
}

void Follower::Update() {
    SDL_FPoint mouse;
    SDL_GetMouseState(&mouse.x, &mouse.y);

    int x = mouse.x - center.x - destFRect.x;
    int y = mouse.y - center.y - destFRect.y;

    angle = SDL_atan2(y, x) * (180 / 3.14159) + 90;
}

void Follower::Draw() {
    TextureManager::Draw(tex, &srcFRect, &destFRect, angle, &center, SDL_FLIP_NONE);
}
