#include <bulletsCollider/bulletsCollider.hpp>

void BulletsCollider::AddBox(BulletHitbox* box) {
    boxes.push_back(box);
}

BulletHitbox* BulletsCollider::DoesCollide(SDL_Rect* rect) {
    for (auto box = boxes.begin(); box != boxes.end(); ++box) {
        if (SDL_HasIntersection( (*box)->GetBox(), rect )) {
            auto ret = *box;
            boxes.erase(box);
            return ret;
        }
    }
    return nullptr;
}

void BulletsCollider::Update() {
    for (auto box : boxes) {
        box->Update();
    } 
}

void BulletsCollider::Draw() {
    for (auto box : boxes) {
        box->Draw();
    }    
}

void BulletsCollider::DeleteBox(BulletHitbox* box) {
    for (auto iter = boxes.begin(); iter != boxes.end(); ++iter) {
        if (*iter == box) {
            boxes.erase(iter);
            std::cout << "Hitbox erased from collider" << '\n';
            return;
        }
    }
}

