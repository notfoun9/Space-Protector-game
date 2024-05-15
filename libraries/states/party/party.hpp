#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>

class Game;
class Life;

class Party {
public:
    Party(Game* game, SDL_Renderer* renderer);
    ~Party() = default;
    
    void Run();
    void Update();
    void Render();
private:
    Game* game;
    SDL_Renderer* renderer;


    Entity mouse;
    Entity background;
    Entity lifes;
    Entity base;
    Entity bulsLeft;

    Entity launcher;

    Entity spawner;
    SDL_Event event;

    Entity gameLost;
    Entity gameWon;

    int gameState = 0;
} ;