#include <simpleTexture/simpleTexture.hpp>
#include <texture_manager/texture_manager.hpp>
#include <position/position.hpp>
#include <meteorHitbox/meteorHitbox.hpp>

SimpleTexture::SimpleTexture(std::string texName) {
    tex = TextureManager::LoadTexture(texName.data());
}

void SimpleTexture::Init() {
    if (owner->HasComponent<PositionComponent>()) {
        auto& pos = owner->GetComponent<PositionComponent>();
        destRect.x = std::round(pos.X());
        destRect.y = std::round(pos.Y());
        destRect.w = std::round(pos.Width());
        destRect.h = std::round(pos.Height());      
    }
}

SimpleTexture::~SimpleTexture() {
    if (!texIsShared) SDL_DestroyTexture(tex);
}

void SimpleTexture::Draw() {
    TextureManager::Draw(tex, &srcRect, &destRect, flip);
}
void SimpleTexture::Update() {
    auto& pos = owner->GetComponent<PositionComponent>();
    destRect.x = std::round(pos.X() + diff.x);
    destRect.y = std::round(pos.Y() + diff.y);
    destRect.w = std::round(pos.Width());
    destRect.h = std::round(pos.Height());
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