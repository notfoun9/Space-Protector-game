#include <meteorHitbox/meteorHitbox.hpp>
#include <position/position.hpp>
#include <short_names/short_names.hpp>
#include <texture_manager/texture_manager.hpp>

void MeteorHitbox::Init() {
    auto& pos = owner->GetComponent<PositionComponent>();

    box.w = pos.Width() * 9 / 11;
    box.h = pos.Height() * 9 / 19;

    difX = pos.Width() / 11;
    difY = pos.Height() * 9 / 19;

    tex = TextureManager::LoadTexture("../../assets/hitbox.png");
}

void MeteorHitbox::Update() {
    if (box.y > 600) {
        owner->Destroy();
        Life::MakeDamage(1);
    }
    box.x = std::round(owner->GetComponent<PositionComponent>().X() + difX);
    box.y = std::round(owner->GetComponent<PositionComponent>().Y() + difY);
}

void MeteorHitbox::Draw() {
    if (Hitboxes::Active()) {
        TextureManager::Draw(tex, NULL, &box, SDL_FLIP_NONE);
    }
}