#pragma once

#include <ECS/ECS.hpp>

class SimpleTexture : public Component {
public:
    SimpleTexture(std::string texName);
    ~SimpleTexture();

    void Draw() override;
    void Update() override;
    
    void SetBoarders(int x, int y, int w, int h);
    void SetShape(int w, int h);

private:
    SDL_Rect srcRect;
    SDL_Rect destRect;

    SDL_Texture* tex;
} ; 