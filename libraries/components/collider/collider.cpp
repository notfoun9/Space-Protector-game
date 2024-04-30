#include<collider/collider.hpp>

void Collider::AddBox(BulletHitbox* box) {
    boxes.push_back(box);
}

BulletHitbox* Collider::DoesCollide(SDL_Rect* rect) {
    for (auto box = boxes.begin(); box != boxes.end(); ++box) {
        if (SDL_HasIntersection( (*box)->GetBox(), rect)) {
            boxes.erase(box);
            return *box;
        }
    }
    return nullptr;
}

void Collider::Update() {
    for (auto box : boxes) {
        box->Update();
    }
}

void Collider::Draw() {
    for (auto box : boxes) {
        box->Draw();
    }    
}

void Collider::DeleteBox(BulletHitbox* box) {
    for (auto iter = boxes.begin(); iter != boxes.end(); ++iter) {
        if (*iter == box) {
            boxes.erase(iter);
            std::cout << "Hitbox erased from collider" << '\n';
            return;
        }
    }
}