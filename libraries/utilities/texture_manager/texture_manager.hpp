#pragma once

#include <game/game.hpp>

class TextureManager {
public:
    [[nodiscard]] static SDL_Texture* LoadTexture(const char *fileName);
    static void Draw(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect* dest);
} ;
