#pragma once

#include <game/game.hpp>

class Menu {
public:
    Menu(std::shared_ptr<Game> game, SDL_Window* window, SDL_Renderer* renderer);
    ~Menu() = default;
    
    void Run();
    void Update();
    void Render();
private:
    std::shared_ptr<Game> game;
    SDL_Window* window;
    SDL_Renderer* renderer;
} ;