#include <bulletHitbox/bulletHitbox.hpp>

BulletHitbox::BulletHitbox(Bullet* bul) : owner(bul), box({0,0,0,0}) {
    int len = owner->owner->GetCenter()->y;
    float angle = owner->GetAngle() * (3.14f / 180);
    difX = (len - 10) * SDL_cos(angle);
    difY = len * (1.0f - SDL_sin(angle)) + 10 * SDL_sin(angle);
    std::cout << angle << '\n';
    box.w = 18;
    box.h = 18;
    tex = TextureManager::LoadTexture("../../assets/hitbox.png");


    std::cout << difX << ' ' << difY << '\n';
    std::cout << len << '\n';
}

void BulletHitbox::Draw() {
    TextureManager::Draw(tex, &src, &box, SDL_FLIP_NONE);
}

void BulletHitbox::Update() {
    box.x = owner->GetDest().x - difX;
    box.y = owner->GetDest().y + difY - 10;
}