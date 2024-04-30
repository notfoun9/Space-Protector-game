#include <simpleTexture/simpleTexture.hpp>
#include <texture_manager/texture_manager.hpp>
#include <position/position.hpp>
#include <meteorHitbox/meteorHitbox.hpp>

SimpleTexture::SimpleTexture(std::string texName) {
    tex = TextureManager::LoadTexture(texName.data());
}

void SimpleTexture::Init() {
    auto& pos = owner->GetComponent<PositionComponent>();
    destRect.x = std::round(pos.X());
    destRect.y = std::round(pos.Y());
    destRect.w = std::round(pos.Width());
    destRect.h = std::round(pos.Height());
}

SimpleTexture::~SimpleTexture() {
    SDL_DestroyTexture(tex);
}

void SimpleTexture::Draw() {
    TextureManager::Draw(tex, &srcRect, &destRect, flip);
}
void SimpleTexture::Update() {
    destRect.x = (int)owner->GetComponent<PositionComponent>().X();
    destRect.y = (int)owner->GetComponent<PositionComponent>().Y();
}

void SimpleTexture::SetBoarders(int x, int y, int w, int h) {
    srcRect = {x, y, w, h};
}


void SimpleTexture::Flip() {
    flip = SDL_FLIP_HORIZONTAL;
}

void SimpleTexture::Unflip() {
    flip = SDL_FLIP_NONE;
}