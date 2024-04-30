#pragma once 

#include <ECS/ECS.hpp>

#include <Vector2D/Vector2D.hpp>

class PositionComponent : public Component {
public:
    PositionComponent() = default;
    PositionComponent(float x, float y) noexcept ;
    PositionComponent(float x, float y, float w, float h) noexcept ;
    ~PositionComponent() = default;

    float X() noexcept;
    float Y() noexcept;
    float Width() noexcept;
    float Height() noexcept;
    
    void SetShape(float w, float h);
    
    void SetPos(float x, float y); 
    void Move(float x, float y);
private:
    Vector2D position;

    float width = 32;
    float height = 32;

    float scale = 1;
} ;