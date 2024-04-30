#pragma once

#include <game/game.hpp>
#include <shooter/shooter.hpp>
#include <Vector2D/Vector2D.hpp>
#include <bulletHitbox/bulletHitbox.hpp>
class Shooter;
class BulletHitbox;

class Bullet {
public:
    Bullet(Shooter* owner);
    ~Bullet();

    void Update();
    void Draw();
    void Destroy();
    float GetAngle() { return angle; }
    Shooter* owner;
    SDL_Rect& GetDest() { return destRect; }

    BulletHitbox* hitbox;
private:
    float angle;
    Vector2D accuratePos;
    Vector2D velocity;

    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
} ;