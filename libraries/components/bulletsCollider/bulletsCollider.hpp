#pragma once 

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <bulletHitbox/bulletHitbox.hpp>

class BulletsCollider : public Component {
public:
    BulletsCollider() = default;
    ~BulletsCollider() = default;

    void Update() override;
    void Draw() override;
    void AddBox(BulletHitbox* box);
    void DeleteBox(BulletHitbox* box);
    BulletHitbox* DoesCollide(SDL_Rect* rect);
private:    
    std::list<BulletHitbox*> boxes;
} ;