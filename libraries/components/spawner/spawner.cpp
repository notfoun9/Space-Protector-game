#include <spawner/spawner.hpp>
#include <animatedTexture/animatedTexture.hpp>
#include <short_names/short_names.hpp>
#include <meteorHitbox/meteorHitbox.hpp>
#include <position/position.hpp>

Spawner::Spawner(int rate_, Vector2D velocity_) : rate(rate_), velocity(velocity_) {
    active = 0;
}

Spawner::~Spawner() {
    meteors.Clear();
}

void Spawner::Update() {
    if (active == false) return;

    if (SDL_GetTicks() - lastTick >= rate) {
        lastTick = SDL_GetTicks();
        Spawn();
        std::cout << "new meteor" << '\n';
    }

    meteors.Update();
    meteors.Refresh();
}

void Spawner::Draw() {
    meteors.Draw();
}

void Spawner::Spawn() {
    auto& meteor = meteors.AddEntity();
    int x = rand() % 850 + 200;
    float size = 5.0f + float(rand() % 250) / 100;

    std::cout << size << '\n';
    meteor.AddComponent<PositionComponent>(x, 0 - 19 * size, 11 * size, 19 * size);
    meteor.AddComponent<AnimatedTexture>(ShortNames::animatedMeteor);
    auto& tex = meteor.GetComponent<AnimatedTexture>();
    tex.AddAnimation("fall", 0, 4, 150);
    tex.Play("fall");
    tex.SetBoarders(0,0,11,19);
    meteor.AddComponent<MeteorHitbox>();

    meteor.GetComponent<PositionComponent>().SetVelocity(0, 3);
    meteor.GetComponent<PositionComponent>().SetSpeed(1);
}