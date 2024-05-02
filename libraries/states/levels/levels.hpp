#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>

class Levels {
public:
    Levels(std::shared_ptr<Game> game, SDL_Renderer* renderer);
    ~Levels() = default;

    void Run();
    void Update();
    void Render();
private:
    Manager buttons;

    std::shared_ptr<Game> game;
    SDL_Renderer* renderer;
} ;