#pragma once

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

    long long ticksSinceJoined = 0;
} ;

static const std::vector<std::string> 
    levelNames = {"1: Easy Start",         "2: Make it Harder!",  "3: Hurry up!",    "4: New Conditions",
                  "5: Stressful situation", "6: Kill the insect", "7: A long night", "8: CHAOS EVERYWHERE"};