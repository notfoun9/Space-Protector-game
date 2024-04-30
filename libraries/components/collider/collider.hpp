#pragma once 

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <bulletHitbox/bulletHitbox.hpp>

class Collider : public Component {
public:
    Collider() = default;
    ~Collider() = default;

    void Update() override;
    void Draw() override;
    void AddBox(BulletHitbox* box);
    void DeleteBox(BulletHitbox* box);
    BulletHitbox* DoesCollide(SDL_Rect* rect);
private:    
    std::list<BulletHitbox*> boxes;
} ;