#pragma once

#include <game/game.hpp>
#include <short_names/short_names.hpp>
#include <texture_manager/texture_manager.hpp>

struct ReusedTextures {
    static void Init() {
        bulletTex = TextureManager::LoadTexture(ShortNames::bullet.data());;
        hitboxTex = TextureManager::LoadTexture("../../assets/hitbox.png");;
        meteorTex = TextureManager::LoadTexture(ShortNames::animatedMeteor.data());
        std::cout << "Reusable textures are initialised" << '\n';
    }
    inline static SDL_Texture* bulletTex;
    inline static SDL_Texture* hitboxTex;
    inline static SDL_Texture* meteorTex;
};
