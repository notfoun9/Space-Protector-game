#include <shooter/shooter.hpp>
#include <follower/follower.hpp>

Shooter::Shooter(SDL_Texture* bulTex) {
    tex = bulTex;
}

void Shooter::Init() {

}

void Shooter::SetSize(float size) {
    angle = owner->GetComponent<Follower>().GetAngle();
    SDL_Rect temp =  owner->GetComponent<Follower>().GetDest();

    destRect.w = size * baseW;
    destRect.h = size * baseH;
    destRect.y = temp.y;
    destRect.x = temp.x + temp.w / 2 - destRect.w / 2;

    center.y = owner->GetComponent<Follower>().GetCenter()->y;
    center.x = destRect.w / 2;
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
    if (bulletsLeft > 0) {
        Bullet* bul = new Bullet(this);
        bul->SetAcceleration(0,-0.06);
        bullets.insert(bul);
        --bulletsLeft;
    }
    std::cout << "Bullets left: " << bulletsLeft << '\n';
}