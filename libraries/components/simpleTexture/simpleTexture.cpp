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
        destFRect.x = std::round(pos.X());
        destFRect.y = std::round(pos.Y());
        destFRect.w = std::round(pos.Width());
        destFRect.h = std::round(pos.Height());      
    }
}

SimpleTexture::~SimpleTexture() {
    if (!texIsShared) SDL_DestroyTexture(tex);
}

void SimpleTexture::Draw() {
    TextureManager::Draw(tex, &srcFRect, &destFRect, flip);
}

void SimpleTexture::Update() {
    auto& pos = owner->GetComponent<PositionComponent>();
    destFRect.x = std::round(pos.X() + diff.x);
    destFRect.y = std::round(pos.Y() + diff.y);
    destFRect.w = std::round(pos.Width());
    destFRect.h = std::round(pos.Height());
}

void SimpleTexture::SetBoarders(float x, float y, float w, float h) {
    srcFRect = {x, y, w, h};
}


void SimpleTexture::Flip() {
    flip = SDL_FLIP_HORIZONTAL;
}

void SimpleTexture::Unflip() {
    flip = SDL_FLIP_NONE;
}
