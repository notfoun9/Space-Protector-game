#pragma once

#ifndef Game_hpp
#define Game_hpp

#include "src/inc/SDL2/SDL.h"
#include "src/inc/SDL2/SDL_image.h"
#include "src/inc/SDL2/SDL_ttf.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <array>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <memory>

class Game {
public:
    Game();
    ~Game();

    void Init(const char* title, int xPos, int yPos, int widht, int height, bool fullscreen);
    void Run(); 
    bool IsRunning();
    void Quit();

    void ToggleFullscreen();
    
    static SDL_Renderer *renderer;
    static SDL_Event event;

    bool inMenu = 1;
private:
    SDL_Window *window;
    bool isRunning = 1;
    bool fullscreen_ = 0;
} ;
#endif 