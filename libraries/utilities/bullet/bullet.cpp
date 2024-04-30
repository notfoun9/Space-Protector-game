#include <bullet/bullet.hpp>
#include <bulletHitbox/bulletHitbox.hpp>
#include <bulletsCollider/bulletsCollider.hpp>

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

    BulletHitbox* hitBox = new BulletHitbox(this, 1);
    BulletHitbox* backHitBox = new BulletHitbox(this, 0);
    if (!(owner->owner->HasComponent<BulletsCollider>())) {
        owner->owner->AddComponent<BulletsCollider>();
    }
    owner->owner->GetComponent<BulletsCollider>().AddBox(hitBox);
    owner->owner->GetComponent<BulletsCollider>().AddBox(backHitBox);
    hitbox = hitBox;
    backHitbox = backHitBox;
}
Bullet::~Bullet() {
    owner->owner->GetComponent<BulletsCollider>().DeleteBox(hitbox);
    owner->owner->GetComponent<BulletsCollider>().DeleteBox(backHitbox);
    delete hitbox;
    delete backHitbox;
    std::cout << "Bullet Destroyed" << '\n';
}

void Bullet::Update() {
    accuratePos.x -= velocity.x;
    accuratePos.y -= velocity.y;

    destRect.x = std::round(accuratePos.x);
    destRect.y = std::round(accuratePos.y);

    if (std::abs(destRect.x) > 2000 || std::abs(destRect.y) > 2000) {
        owner->AddBulletToDest(this);
    }
}

void Bullet::Draw() {
    TextureManager::Draw(texture, &srcRect, &destRect, angle - 90, owner->GetCenter(), SDL_FLIP_NONE);
}