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

    SDL_FRect& GetDest() {
        return destFRect;
    }
    void Flip();
    void Unflip();
    virtual void SetBoarders(float x, float y, float w, float h);
    void SetDiff(float x, float y) { diff = {x,y}; }

protected:
    SDL_FlipMode flip = SDL_FLIP_NONE;
    SDL_FRect srcFRect;
    SDL_FRect destFRect = {0,0,0,0};

    Vector2D diff = {0,0};
    SDL_Texture* tex;
    bool texIsShared = 0;
} ; 
