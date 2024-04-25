#pragma once 

#include <ECS/ECS.hpp>

#include <Vector2D/Vector2D.hpp>

class PositionComponent : public Component {
public:
    PositionComponent() = default;
    PositionComponent(float x, float y) noexcept ;
    ~PositionComponent() = default;

    float X() noexcept;
    float Y() noexcept;

    void SetPos(float x, float y); 
    void Move(float x, float y);
private:
    Vector2D position;
} ;