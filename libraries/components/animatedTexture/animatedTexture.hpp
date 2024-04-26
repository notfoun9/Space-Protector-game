#pragma once

#include <ECS/ECS.hpp>
#include <simpleTexture/simpleTexture.hpp>
#include <animation/animation.hpp>

class AnimatedTexture : public SimpleTexture {
public:
    AnimatedTexture(std::string texName);
    ~AnimatedTexture() = default;

    void Update() override;
    
    void Play(std::string animName);
    void AddAnimation(std::string name, int idx, int frames, int speed);
    

private:
    int animIndex = 0;
    int frames = 0;
    int speed = 0;
    std::unordered_map<std::string, Animation> animations;
} ; 