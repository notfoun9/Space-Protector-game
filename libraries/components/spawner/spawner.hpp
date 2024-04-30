#pragma once

#include <game/game.hpp>
#include <ECS/ECS.hpp>
#include <Vector2D/Vector2D.hpp>

class Spawner : public Component {
public:
    Spawner(int rate, Vector2D velocity);
    ~Spawner();

    void Update() override;
    void Draw() override;
    void SeBoarders(int  left, int right);
    void SetSize(int w, int h);

    void Start() { 
        active = 1; 
        lastTick = SDL_GetTicks();
    }
    void Stop() { active = 0; }

    void Spawn();
    Manager* GetMeteors() { return &meteors; }
private:
    Manager meteors;

    int rate;
    Vector2D velocity;
    int leftBoarder;
    int rightBoarder;

    int w = 0;
    int h = 0;

    bool active;
    int lastTick = 0;
} ;