#pragma once

#include <game/game.hpp>

class TextureManager {
public:
    [[nodiscard]] static SDL_Texture* LoadTexture(const char *fileName);

    static void Draw(SDL_Texture* texture, const SDL_FRect* src, const SDL_FRect* dest, SDL_FlipMode flip);

    static void Draw(SDL_Texture* texture, const SDL_FRect* src, const SDL_FRect* dest, double angle, SDL_FPoint* center, SDL_FlipMode flip);
};
