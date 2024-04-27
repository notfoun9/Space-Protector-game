#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>

class Shooter : public Component {
public:
    Shooter(std::string bullet, float speed);
    ~Shooter();

    void Update() override;
    void Draw() override;
    void Shoot();
private:
    std::vector<Bullet*> bullets;
    float speed;
    float angle;
} ;