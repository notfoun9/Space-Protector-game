#pragma once

#include <ECS/ECS.hpp>

class SimpleTexture : public Component {
public:
    SimpleTexture() = default;
    SimpleTexture(std::string texName);
    virtual ~SimpleTexture();

    virtual void Draw() override;
    virtual void Update() override;
    virtual void Init() override;

    virtual void SetBoarders(int x, int y, int w, int h);

protected:
    SDL_Rect srcRect;
    SDL_Rect destRect = {0,0,0,0};

    SDL_Texture* tex;
} ; 