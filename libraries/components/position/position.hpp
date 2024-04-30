#pragma once 

#include <ECS/ECS.hpp>

#include <Vector2D/Vector2D.hpp>

class PositionComponent : public Component {
public:
    PositionComponent() = default;
    PositionComponent(float x, float y) noexcept ;
    PositionComponent(float x, float y, float w, float h) noexcept ;
    ~PositionComponent() = default;

    void Update() override;
    float X() noexcept;
    float Y() noexcept;
    float Width() noexcept;
    float Height() noexcept;
    
    Vector2D& GetVelocity() { return velocity; } 
    void SetVelocity(int x, int y) { velocity.x = x; velocity.y = y; } 
    void SetSpeed(const int speed_) { speed = speed_; }
    void SetShape(float w, float h);
    
    void SetPos(float x, float y); 
private:
    Vector2D position;

    float width = 32;
    float height = 32;

    float scale = 1;

    float speed = 0;
    Vector2D velocity;
} ;