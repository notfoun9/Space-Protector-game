#pragma once

#include <game/game.hpp>

class Party {
public:
    Party(std::shared_ptr<Game> game, SDL_Renderer* renderer);
    ~Party() = default;
    
    void Run();
    void Update();
    void Render();
private:
    std::shared_ptr<Game> game;
    SDL_Renderer* renderer;
} ;