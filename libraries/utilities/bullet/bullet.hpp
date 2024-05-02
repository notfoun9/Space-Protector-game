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
    void SetAcceleration(float x, float y) { acceleration.x = x; acceleration.y = y; } 

    BulletHitbox* hitbox;
    BulletHitbox* backHitbox;
private:
    float angle;
    Vector2D accuratePos;
    Vector2D velocity;
    Vector2D acceleration = {0,0};

    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
} ;