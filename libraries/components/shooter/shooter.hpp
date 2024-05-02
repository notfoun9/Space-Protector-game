#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <bullet/bullet.hpp>
#include <texture_manager/texture_manager.hpp>

class Bullet;

class Shooter : public Component {
public:
    Shooter(std::string bullet, float speed);
    ~Shooter();

    void Init() override;
    float GetSpeed() { return speed; }
    float GetAngle() { return angle; }
    SDL_Point* GetCenter() { return &center; }
    SDL_Texture* GetTex() { return tex; }

    void Update() override;
    void Draw() override;
    void Shoot();
    void SetSrc(int x, int y, int w, int h) { srcRect = {x,y,w,h}; }
    void SetSize(float size);
    void AddBullets(int num) { bulletsLeft += num; }
 
    void AddBulletToDest(Bullet* bul) { bulletsToDestroy.push(bul); }

    SDL_Rect destRect;
    SDL_Rect srcRect;
    std::unordered_set<Bullet*> bullets;
private:
    SDL_Texture* tex;
    SDL_Point center;

    std::stack<Bullet*> bulletsToDestroy;
    float angle;
    float speed;

    int bulletsLeft = 0;
} ;

