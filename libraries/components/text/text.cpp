#include<text/text.hpp>
#include<texture_manager/texture_manager.hpp>
#include <position/position.hpp>

Text::Text(std::string fontPath, int fontSize, const SDL_Color color_) :
    color(color_) {
    TTF_Init();
    const char* f = fontPath.data();
    font = TTF_OpenFont(f, fontSize);
    std::cerr << TTF_GetError() << '\n';
    if (!font) {
        std::cerr << "Failed to load font\n";
    }
}

Text::~Text() {
    TTF_CloseFont(font);
    SDL_DestroyTexture(textTex);
}

void Text::Init() {
    auto& tmp = owner->GetComponent<PositionComponent>();
    destRect.x = tmp.X();
    destRect.y = tmp.Y();
}

void Text::SetSize(int w, int h) {
    destRect.w = w;
    destRect.h = h;
}

void Text::SetMessage(std::string message_) {
    message = message_;
    auto textSurface = TTF_RenderText_Solid(font, message.c_str(), color);

    SDL_DestroyTexture(textTex);
    textTex = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
}

void Text::Update() {
    SetMessage(message);
    SDL_QueryTexture(textTex, nullptr, nullptr, &destRect.w, &destRect.h);
}

void Text::Draw() {
    if (!textTex) std::cerr << "error" << '\n';
    SDL_RenderCopy(Game::renderer, textTex, NULL, &destRect);
}
