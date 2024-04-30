#include <bulletHitbox/bulletHitbox.hpp>

BulletHitbox::BulletHitbox(Bullet* bul) : owner(bul), box({0,0,0,0}) {
    float len = owner->owner->GetCenter()->y;
    float angle = owner->GetAngle() * (3.14f / 180);
    box.w = owner->GetDest().w;
    box.h = owner->GetDest().w;
    
    difX = (len - box.w / 2) * SDL_cos(angle);
    difY = len * (1.0f - SDL_sin(angle)) + box.w * SDL_sin(angle) / 2;
    std::cout << angle << '\n';
    tex = TextureManager::LoadTexture("../../assets/hitbox.png");


    std::cout << difX << ' ' << difY << '\n';
    std::cout << len << '\n';
}

void BulletHitbox::Draw() {
    TextureManager::Draw(tex, &src, &box, SDL_FLIP_NONE);
}

void BulletHitbox::Update() {
    box.x = owner->GetDest().x - difX;
    box.y = owner->GetDest().y + difY - box.w / 2;
}

void BulletHitbox::DestroyOwner() { 
    std::cout << "Hit" << '\n';
    owner->owner->AddBulletToDest(owner);
}