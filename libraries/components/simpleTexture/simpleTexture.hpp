#pragma once

#include <ECS/ECS.hpp>
#include <Vector2D/Vector2D.hpp>

class SimpleTexture : public Component {
public:
    SimpleTexture() = default;
    SimpleTexture(std::string texName);
    virtual ~SimpleTexture();

    virtual void Draw() override;
    virtual void Update() override;
    virtual void Init() override;

    SDL_Rect& GetDest() {
        return destRect;
    }
    void Flip();
    void Unflip();
    virtual void SetBoarders(int x, int y, int w, int h);
    void SetDiff(float x, float y) { diff = {x,y}; }

protected:
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Rect srcRect;
    SDL_Rect destRect = {0,0,0,0};

    Vector2D diff = {0,0};
    SDL_Texture* tex;
    bool texIsShared = 0;
} ; 
