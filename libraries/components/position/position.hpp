#pragma once 

#include <ECS/ECS.hpp>

class PositionComponent : public Component {
public:
    PositionComponent() noexcept;
    PositionComponent(float x, float y) noexcept;
    PositionComponent(float x, float y, float w, float h) noexcept;
    ~PositionComponent();

    PositionComponent(PositionComponent&& rhs);
    PositionComponent(const PositionComponent& rhs);
    PositionComponent& operator=(PositionComponent&& rhs);
    PositionComponent& operator=(const PositionComponent& rhs);

    void Update() override;
    float X() noexcept;
    float Y() noexcept;
    float Width() noexcept;
    float Height() noexcept;

    void SetVelocity(int x, int y);
    void SetAcceleration(float x, float y);
    void SetSpeed(const float speed_);
    void SetShape(float w, float h);
    
    void SetPos(float x, float y); 
private:

    struct Impl;
    std::unique_ptr<Impl> pimpl;
} ;