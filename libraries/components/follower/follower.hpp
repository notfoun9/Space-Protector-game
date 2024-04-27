#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <simpleTexture/simpleTexture.hpp>

class Follower : public SimpleTexture {
public:
    Follower(std::string tex);
    ~Follower() = default;

    void SetCenter(int x, int y);
    void Update() override;
    void Draw() override;
private:
    float angle;
    SDL_Point center;
} ;