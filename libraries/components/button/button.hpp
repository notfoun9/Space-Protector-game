#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <Vector2D/Vector2D.hpp>

class Button : public Component {
public:
    Button(std::string selTex, std::string notSelTex);
    ~Button() override;

    void Init() override;
    void Update() override;
    void Draw() override;

    bool IsSelected() const { return selected; }

    void SetDiff(float x, float y) { diff = {x,y}; }
private:
    bool selected = 0;
    
    SDL_FRect destRect;
    Vector2D diff = {0,0};
    SDL_Texture* selectedTex;
    SDL_Texture* notSelectedTex;
} ; 
