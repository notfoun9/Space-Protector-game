#pragma once

#include <game/game.hpp>
#include <simpleTexture/simpleTexture.hpp>

class Mouse : public SimpleTexture{
public:
    Mouse(std::string str);
    ~Mouse() = default;

    void Update() override;

    SDL_FRect* getTip();
private:
    SDL_FRect tip;
} ; 
