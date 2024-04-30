#include <meteorHitbox/meteorHitbox.hpp>
#include <position/position.hpp>
#include <short_names/short_names.hpp>
#include <texture_manager/texture_manager.hpp>

void MeteorHitbox::Init() {
    auto& pos = owner->GetComponent<PositionComponent>();

    box.x = pos.X() + pos.Width() / 11;
    box.w = pos.Width() * 9 / 11;

    box.h = pos.Height() * 9 / 19;
    box.y = pos.Y() + box.h;

    accuratePos.x = box.x;
    accuratePos.y = box.y;
    // tex = TextureManager::LoadTexture("../../assets/hitbox.png");
}

void MeteorHitbox::Update() {
    accuratePos.x += owner->GetComponent<PositionComponent>().GetVelocity().x;
    accuratePos.y += owner->GetComponent<PositionComponent>().GetVelocity().y;
    if (box.y > 600) {
        owner->Destroy();
        std::cout << "damage" << '\n';
    }
    box.x = std::round(accuratePos.x);
    box.y = std::round(accuratePos.y);
}

// void MeteorHitbox::Draw() {
//     TextureManager::Draw(tex, NULL, &box, SDL_FLIP_NONE);
// }