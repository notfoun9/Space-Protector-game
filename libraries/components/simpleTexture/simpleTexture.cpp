#include <simpleTexture/simpleTexture.hpp>
#include <texture_manager/texture_manager.hpp>
#include <position/position.hpp>

SimpleTexture::SimpleTexture(std::string texName) {
    tex = TextureManager::LoadTexture(texName.data());
}

void SimpleTexture::Init() {
    destRect.x = (int)owner->GetComponent<PositionComponent>().X();
    destRect.y = (int)owner->GetComponent<PositionComponent>().Y();
    destRect.w = (int)owner->GetComponent<PositionComponent>().Width();
    destRect.h = (int)owner->GetComponent<PositionComponent>().Height();
}

SimpleTexture::~SimpleTexture() {
    SDL_DestroyTexture(tex);
}

void SimpleTexture::Draw() {
    TextureManager::Draw(tex, &srcRect, &destRect);
}
void SimpleTexture::Update() {
    destRect.x = (int)owner->GetComponent<PositionComponent>().X();
    destRect.y = (int)owner->GetComponent<PositionComponent>().Y();
}

void SimpleTexture::SetBoarders(int x, int y, int w, int h) {
    srcRect = {x, y, w, h};
}
