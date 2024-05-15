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
#include <texture_manager/texture_manager.hpp>

enum settings {METEOR_SIZE_MIN,  METEOR_SIZE_MAX,  METEOR_FREQUENCY,  METEOR_SPEED,         METEOR_NUM,  
               BUL_SIZE,         BUL_NUM,          BUL_SPEED,         METEOR_ACCELERATION,  LIVES};

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

                                  // LVL  1     2     3     4     5    6     7    8
    std::vector<float> meteorSizeMin   = {5,    5,    4,    2,    6,   3,    5,    6};
    std::vector<float> meteorSizeMax   = {7,    6,    6,    9,    7,   4,    8,    8};
    std::vector<float> meteorFrequency = {1000, 1000, 500,  1000, 700, 700,  800, 500};
    std::vector<float> meteorSpeed     = {3,    3.5,  4.5,  4,    3.5, 2,    3,    4}; 
    std::vector<float> meteorNum       = {15,   20,   20,   20,   40,  20,   50,   20};
    std::vector<float> bulletSize      = {3.5,  3,    3,    4,    3,   4,    3,    3.5};
    std::vector<float> bulletNum       = {25,   30,   25,   25,   50,  25,   60,   25};
    std::vector<float> bulletSpeed     = {20,   25,   35,   30,   22,  20,   25,   50};
    std::vector<float> meteorAccel     = {0,    0,    3,    3,    3,   3,    0,    3};
    std::vector<float> lives           = {5,    3,    5,    3,    5,   5,    4,    1};

    auto SetSettings(int lvl) {
        settings = std::vector<float>{meteorSizeMin[lvl], meteorSizeMax[lvl], meteorFrequency[lvl], meteorSpeed[lvl], meteorNum[lvl],       
                                      bulletSize[lvl],    bulletNum[lvl],     bulletSpeed[lvl],     meteorAccel[lvl], lives[lvl]};
    }
    float Setting(size_t param) {
        return settings[param];
    }

    bool inMenu = 1;
    bool inParty = 0;
private:

    std::vector<float> settings;
    bool isRunning = 1;
    bool fullscreen_ = 0;
    SDL_Window *window;
} ;




struct Hitboxes {
    static bool Active() { return active; }
    static void Switch() {
        if (SDL_GetTicks64() - tick > 500) {
            tick = SDL_GetTicks64();
            active = !active;
            std::cout << (active ? "Hitboxes Shown" : "Hitboxes Hidden") << std::endl;
        }
    }

    inline static long long tick = 0;
    inline static bool active = 0;
};



class Life {
public:
    static void Init() {
        SDL_Surface* tmpSurface = IMG_Load("../../assets/heart.png");
        SDL_Texture* textureFromSurface = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
        if (!textureFromSurface) std::cerr << "texture is not created" << '\n';
        SDL_FreeSurface(tmpSurface);

        heart = textureFromSurface;
    }
    static void SetHP(int num) { hp = num; }
    static int hpLeft() { return hp; }

    static void MakeDamage(int damage) { hp -= damage; }
    static void Draw() { 
        for (int i = 0; i < hp; ++i) {
            SDL_Rect dest = {30, 30 + 90 * i, 80, 80};
            SDL_RenderCopyEx(Game::renderer, heart, NULL, &dest, 0.0, NULL, SDL_FLIP_NONE);
        }
    }
private:
    inline static SDL_Texture* heart;
    inline static int hp = 0;
} ;

#endif 