#pragma once

#include <game/game.hpp>

class TextureManager {
public:
    [[nodiscard]] static SDL_Texture* LoadTexture(const char *fileName);
    static void Draw(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect* dest, SDL_RendererFlip flip);
    static void Draw(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect* dest, double angle, SDL_Point* center, SDL_RendererFlip flip);
} ;
