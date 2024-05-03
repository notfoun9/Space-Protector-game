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
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <memory>

class Game {
public:
    Game() = default;
    ~Game();

    void Init(const char* title, int xPos, int yPos, int widht, int height, bool fullscreen);
    void Run(); 
    bool& IsRunning();
    void Quit();

    void ToggleFullscreen();
    
    static SDL_Renderer *renderer;
    static SDL_Event event;
    bool text = 0;
    
    enum settings {METEOR_SIZE_MIN, METEOR_SIZE_MAX, METEOR_FREQUENCY, METEOR_SPEED, METEOR_NUM, BUL_SIZE, BUL_NUM, BUL_SPEED, METEOR_ACCELERATION, LIFES};
    std::tuple<float, float, int, float, int, int, float, float, int, int> settings = {};

    std::vector<std::tuple<float, float, int, float, int, int, float, float, int, int>> lvls = {
        {6, 8, 1500, 2, 15, 3.5, 25, 14, 3, 5}, {6, 8, 1300, 3.5, 20, 3, 30, 20, 3, 5}, {5, 6, 1200, 3.5, 20, 3, 25, 18, 3, 5},
        {2, 9, 1200, 2, 40, 4.5, 50, 17, 3, 5}, {6, 7, 700, 3.5, 40, 3, 50, 22, 3, 5}, {5, 6, 100, 2, 20, 3, 100, 8, 3, 5},
        {5, 6, 100, 2, 20, 3, 100, 8, 3, 5}, {5, 6, 100, 2, 20, 3, 100, 8, 3, 5}
    };

    bool inMenu = 1;
    bool inParty = 0;
private:

    bool isRunning = 1;
    SDL_Window *window;
    bool fullscreen_ = 0;
} ;

#endif 