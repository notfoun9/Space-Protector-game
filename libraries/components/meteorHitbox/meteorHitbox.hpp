#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <Vector2D/Vector2D.hpp>
class MeteorHitbox : public Component {
public:
    MeteorHitbox() = default;
    ~MeteorHitbox() = default;

    void Init() override;
    void Update() override;
    void Draw() override;
    
    void Destroy() { owner->Destroy(); }

    SDL_Rect* GetBox() { return &box; }
private:
    SDL_Rect box;
    Vector2D accuratePos = {0,0};

    SDL_Texture* tex;
} ;