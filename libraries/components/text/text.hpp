#pragma once 

#include<game/game.hpp>
#include <ECS/ECS.hpp>
#include "../../src/inc/SDL2/SDL_ttf.h"

class Text : public Component {
public:
    Text(std::string fontPath, int fontSize, const SDL_Color color);
    ~Text();
    void SetMessage(std::string message);
    void AddMessage(std::string extraMes);
    void Draw() override;
    void Update() override;
    void Init() override;

    void SetSize(int w, int h);
private:
    SDL_Surface* textSurface;
    SDL_Texture* textTex = nullptr;

    SDL_Rect destRect;
    std::string message;
    SDL_Color color;

    TTF_Font* font;
} ;
