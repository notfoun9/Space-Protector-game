#include <position/position.hpp>
PositionComponent::PositionComponent(float x, float y) noexcept{
    position.x = x;
    position.y = y;
}

float PositionComponent::X() noexcept {
    return position.x;
}
float PositionComponent::Y() noexcept {
    return position.y;
}

void PositionComponent::SetPos(float x, float y) {
    position.x = x;
    position.y = y;
}

void PositionComponent::Move(float x, float y) {
    position += Vector2D(x,y);
}
 