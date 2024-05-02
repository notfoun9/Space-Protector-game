#include <button/button.hpp>
#include <texture_manager/texture_manager.hpp>
#include <position/position.hpp>

Button::Button(std::string selTex, std::string notSelTex) {
    selectedTex = TextureManager::LoadTexture(selTex.data());
    notSelectedTex = TextureManager::LoadTexture(notSelTex.data());
}

Button::~Button() {
    SDL_DestroyTexture(selectedTex);
    SDL_DestroyTexture(notSelectedTex);
}

void Button::Init() {
    auto& pos = owner->GetComponent<PositionComponent>();
    
    destRect.x = pos.X();
    destRect.y = pos.Y();
    destRect.w = pos.Width();
    destRect.h = pos.Height();
}

void Button::Update() {
    SDL_Rect tmp = {0,0,2,2};
    SDL_GetMouseState(&tmp.x, &tmp.y);
    if (SDL_HasIntersection(&destRect, &tmp)) {
        selected = true;
    }
    else {
        selected = false;
    }
}

void Button::Draw() {
    if (selected) {
        TextureManager::Draw(selectedTex, NULL, &destRect, SDL_FLIP_NONE);
    }
    else {
        TextureManager::Draw(notSelectedTex, NULL, &destRect, SDL_FLIP_NONE);
    }
}