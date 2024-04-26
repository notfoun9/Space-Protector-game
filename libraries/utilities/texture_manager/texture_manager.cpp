#include <texture_manager/texture_manager.hpp>
#include <mouse/mouse.hpp>

[[nodiscard]] SDL_Texture* TextureManager::LoadTexture(const char* texture) {
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* textureFromSurface = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    if (!textureFromSurface) std::cerr << "texture is not created" << '\n';
    SDL_FreeSurface(tmpSurface);

    return textureFromSurface;
}

void TextureManager::Draw(SDL_Texture* texture, const SDL_Rect* src, const SDL_Rect *dest) {
    SDL_RenderCopy(Game::renderer, texture, src, dest);
}