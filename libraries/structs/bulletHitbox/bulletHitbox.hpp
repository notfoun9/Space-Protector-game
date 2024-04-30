#pragma once

#include <game/game.hpp>
#include <bullet/bullet.hpp>

class Bullet;

class BulletHitbox {
public:
    BulletHitbox(Bullet* owner_, bool back);
    ~BulletHitbox() {
        std::cout << "Hitbox deleted" << '\n';
    }
    // void Draw();
    void Update();
    SDL_Rect* GetBox() { return &box; }

    void DestroyOwner();
private:
    Bullet* owner;
    SDL_Rect box;
    int difX;
    int difY;

    // SDL_Texture* tex;
    // SDL_Rect src = {0,0,9,9};
} ;