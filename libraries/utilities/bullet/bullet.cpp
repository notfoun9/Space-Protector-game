#include <bullet/bullet.hpp>
#include <bulletHitbox/bulletHitbox.hpp>
#include <collider/collider.hpp>
Bullet::Bullet(Shooter* owner_) : owner(owner_) {
    angle = owner->GetAngle() + 90;

    velocity.x = owner->GetSpeed() * SDL_cos(angle * (3.14 / 180));
    velocity.y = owner->GetSpeed() * SDL_sin(angle * (3.14 / 180));
    std::cout << angle << '\n';
    std::cout << SDL_sin(angle * (3.14 / 180)) << '\n';
    std::cout << SDL_cos(angle * (3.14 / 180)) << '\n';
    texture = owner->GetTex();
    destRect = owner->destRect;
    srcRect = owner->srcRect;

    accuratePos.x = destRect.x;
    accuratePos.y = destRect.y;

    BulletHitbox* hitBox = new BulletHitbox(this);
    if (!(owner->owner->HasComponent<Collider>())) {
        owner->owner->AddComponent<Collider>();
    }
    owner->owner->GetComponent<Collider>().AddBox(hitBox);
    hitbox = hitBox;
}
Bullet::~Bullet() {
    owner->owner->GetComponent<Collider>().DeleteBox(hitbox);
    delete hitbox;
    std::cout << "Bullet Destroyed" << '\n';
}

void Bullet::Update() {
    accuratePos.x -= velocity.x;
    accuratePos.y -= velocity.y;


    destRect.x = accuratePos.x;
    if (accuratePos.x - float(destRect.x) >= 0.5f) {
        ++destRect.x;
    }
    destRect.y = accuratePos.y;
    if (accuratePos.y - float(destRect.y) >= 0.5f) {
        ++destRect.y;
    }

    if (std::abs(destRect.x) > 2000 || std::abs(destRect.y) > 2000) {
        owner->AddBulletToDest(this);
    }
}

void Bullet::Draw() {
    TextureManager::Draw(texture, &srcRect, &destRect, angle - 90, owner->GetCenter(), SDL_FLIP_NONE);
}