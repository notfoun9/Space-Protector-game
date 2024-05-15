#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <Vector2D/Vector2D.hpp>

class Spawner : public Component {
public:
    Spawner();
    ~Spawner();

    void Update() override;
    void Draw() override;

    void SeBoarders(int left, int right);
    void SetSize(float min, float max);
    void SetVelocity(float x, float y) { velocity = {x,y}; };
    void SetSpeed(float speed_) { speed = speed_; };
    void SetRate(int r) { rate = r; }
    
    void SetMeteorsNum(int mets) { meteorsLeft = mets; }
    int MeteorsLeft() { return meteorsLeft; }

    void Start() { 
        active = 1; 
        lastTick = SDL_GetTicks();
    }
    void Stop() { active = 0; }
    void DeleteMets() { meteors.Clear(); }
    void Spawn();
    Manager* GetMeteors() { return &meteors; }
private:
    Manager meteors;
    Vector2D velocity = {0,0};
    Vector2D acceleration;
    float speed = 1.0f;

    int meteorsLeft = 0;

    int rate;

    int leftBoarder = 0;
    int rightBoarder = 0;

    float minSize = 0;
    float maxSize = 0;

    bool active;
    int lastTick = 0;
} ;