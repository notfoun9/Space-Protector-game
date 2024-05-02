#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>

class Button : public Component {
public:
    Button(std::string selTex, std::string notSelTex);
    ~Button() override;

    void Init() override;
    void Update() override;
    void Draw() override;

    bool IsSelected() const { return selected; }
private:
    bool selected = 0;

    SDL_Rect destRect;
    SDL_Texture* selectedTex;
    SDL_Texture* notSelectedTex;
} ; 