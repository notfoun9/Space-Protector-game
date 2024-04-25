#include <simpleTexture/simpleTexture.hpp>
#include <texture_manager/texture_manager.hpp>
#include <position/position.hpp>

SimpleTexture::SimpleTexture(std::string texName) {
    tex = TextureManager::LoadTexture(texName.data());
}

SimpleTexture::~SimpleTexture() {
    SDL_DestroyTexture(tex);
}

void SimpleTexture::Draw() {
    TextureManager::Draw(tex, &srcRect, &destRect);
}

void SimpleTexture::SetBoarders(int x, int y, int w, int h) {
    srcRect = {x, y, w, h};
}

void SimpleTexture::SetShape(int w, int h) {
    if ((*owner).HasComponent<PositionComponent>() == 0) {
        std::cerr << "Position component must be set";
    }
    else {
        destRect.x = owner->GetComponent<PositionComponent>().X();
        destRect.y = owner->GetComponent<PositionComponent>().Y();
    }
    destRect.w = w;
    destRect.h = h;
}