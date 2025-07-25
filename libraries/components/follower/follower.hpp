#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <simpleTexture/simpleTexture.hpp>

class Follower : public SimpleTexture {
public:
    Follower(std::string tex);
    ~Follower() = default;

    void SetCenter(float x, float y);
    SDL_FPoint* GetCenter() { return &center; }
    void Update() override;
    void Draw() override;

    float GetAngle() { return angle; }
private:
    float angle;
    SDL_FPoint center;
} ;
