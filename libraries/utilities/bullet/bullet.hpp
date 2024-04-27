#pragma once

#include <game/game.hpp>

class Bullet {
public:
    Bullet();
    ~Bullet();

    void Update();
    void Draw();
    void Destroy();

    SDL_Rect* GetHitbox();
private:
    float speed;
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
} ;