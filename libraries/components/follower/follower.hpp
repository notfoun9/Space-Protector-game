#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <simpleTexture/simpleTexture.hpp>

class Follower : public SimpleTexture {
public:
    Follower(std::string tex);
    ~Follower() = default;

    void SetCenter(int x, int y);
    SDL_Point* GetCenter() { return &center; }
    void Update() override;
    void Draw() override;

    float GetAngle() { return angle; }
private:
    float angle;
    SDL_Point center;
} ;