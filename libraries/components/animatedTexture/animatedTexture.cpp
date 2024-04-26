#include <animatedTexture/animatedTexture.hpp>
#include <texture_manager/texture_manager.hpp>

AnimatedTexture::AnimatedTexture(std::string texName) {
    tex = TextureManager::LoadTexture(texName.data());
}

void AnimatedTexture::AddAnimation(std::string name, int idx, int frames, int speed) {
    animations.insert({name, Animation(idx, frames, speed)});
}

void AnimatedTexture::Update() {
    if (speed == 0) {
        std::cerr << "Animation is not set!" << '\n';
        return;
    }
    srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);

    srcRect.y = animIndex * srcRect.h;
}

void AnimatedTexture::Play(std::string animName) {
    frames = animations[animName].frames;
    speed = animations[animName].speed;
    animIndex = animations[animName].index;
}