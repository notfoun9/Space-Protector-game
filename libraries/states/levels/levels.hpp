#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>

class Game;

class Levels {
public:
    Levels(Game* game, SDL_Renderer* renderer);
    ~Levels() = default;

    void Run();
    void Update();
    void Render();
private:
    Manager buttons;
    
    std::vector<Entity*> buts;
    Game* game;
    SDL_Renderer* renderer;


} ;