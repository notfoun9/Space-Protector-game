#include <shooter/shooter.hpp>
#include <follower/follower.hpp>

Shooter::Shooter(std::string bullet, float speed_) : speed(speed_) {
    tex = TextureManager::LoadTexture(bullet.data());
}

void Shooter::Init() {
    angle = owner->GetComponent<Follower>().GetAngle();
    SDL_Rect temp =  owner->GetComponent<Follower>().GetDest();
    destRect.x = temp.x + 19;
    destRect.y = temp.y + 0;
    destRect.w = 18;
    destRect.h = 38;
}

Shooter::~Shooter() {
    for (auto bul : bullets) {
        delete bul;
        SDL_DestroyTexture(tex);
    }
}

void Shooter::Update() {
    angle = owner->GetComponent<Follower>().GetAngle();

    if (Game::event.button.button == SDL_BUTTON_LEFT) {
        Shoot();
    }

    for (auto bullet : bullets) {
        bullet->Update();
    }

    while (!bulletsToDestroy.empty()) {
        bullets.erase(bulletsToDestroy.top());
        delete bulletsToDestroy.top();

        bulletsToDestroy.pop();
    }

}

void Shooter::Draw() {
    for (auto &bullet : bullets) {
        bullet->Draw();
    }
}

void Shooter::Shoot() {
    Bullet* bul = new Bullet(this);
    bullets.insert(bul);
}