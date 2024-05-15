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

enum class Settings {
    METEOR_SIZE_MIN = 0, 
    METEOR_SIZE_MAX = 1, 
    METEOR_FREQUENCY = 2, 
    METEOR_SPEED = 3, 
    METEOR_NUM = 4, 
    BUL_SIZE = 5, 
    BUL_NUM = 6, 
    BUL_SPEED = 7, 
    METEOR_ACCELERATION = 8, 
    LIVES = 9
};

struct LevelSettings {
    
} ; 


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
    
    enum settings {METEOR_SIZE_MIN, METEOR_SIZE_MAX, METEOR_FREQUENCY, METEOR_SPEED, METEOR_NUM, BUL_SIZE, BUL_NUM, BUL_SPEED, METEOR_ACCELERATION, LIVES};
    std::tuple<float, float, int, float, int, int, float, float, int, int> settings = {};

    std::vector<std::tuple<float, float, int, float, int, int, float, float, int, int>> lvls = {
        {6, 8, 1500, 2,   15, 3.5, 25,   2, 3, 5}, 
        {6, 8, 1300, 3.5, 20, 3, 30,    20, 3, 5}, 
        {5, 6, 1200, 3.5, 20, 3, 25,    18, 3, 5},
        {2, 9, 1200, 2,   40, 4.5, 50,  17, 3, 5}, 
        {6, 7, 700, 3.5,  40, 3, 50,    22, 3, 5}, 
        {5, 6, 100, 2,    20, 3, 100,    8, 3, 5},
        {5, 6, 100, 2,    20, 3, 100,    8, 3, 5}, 
        {5, 6, 100, 2,    20, 3, 100,    8, 3, 1}
    };

    std::vector<float> meteorSizeMin   = {6,    6,    5,    2,    6,   5,   5,   5};
    std::vector<float> meteorSizeMax   = {8,    8,    6,    9,    7,   5,   5,   5};
    std::vector<float> meteorFrequency = {1500, 1300, 1200, 1200, 700, 100, 100, 100};
    std::vector<float> meteorSpeed     = {2,    3.5,  3.5,  2,    3.5, 2,   2,   2}; 
    std::vector<float> meteorNum       = {15,   20,   20,   40,   40,  20,  20,  20};
    std::vector<float> bulletSize      = {3.5,  3,    3,    4.5,  3,   3,   3,   3};
    std::vector<float> bulletNum       = {25,   30,   25,   50,   50,  100, 100, 100};
    std::vector<float> bulletSpeed     = {10,   20,   18,   17,   22,  8,   8,   8};
    std::vector<float> meteorAccel     = {3,    3,    3,    3,    3,   3,   3,   3};
    std::vector<float> lives           = {5,    5,    5,    5,    5,   5,   5,   5};

    auto GetLevel(int num) {
        settings = std::make_tuple(meteorSizeMin[num], meteorSizeMax[num], meteorFrequency[num], meteorSpeed[num], meteorNum[num],       
                                   bulletSize[num],    bulletNum[num],     bulletSpeed[num],     meteorAccel[num], lives[num]);
        return settings;
    }



    bool inMenu = 1;
    bool inParty = 0;
private:

    bool isRunning = 1;
    SDL_Window *window;
    bool fullscreen_ = 0;
} ;

#endif 