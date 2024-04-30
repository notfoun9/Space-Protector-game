#include <position/position.hpp>

PositionComponent::PositionComponent(float x, float y) noexcept{
    position.x = x;
    position.y = y;
}
PositionComponent::PositionComponent(float x, float y, float w, float h) noexcept  {
    position.x = x;
    position.y = y;
    width = w;
    height = h;
}

void PositionComponent::Update() {
    if (speed != 0) {
        position += velocity * speed;
    }
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
 
float PositionComponent::Width() noexcept {
    return width;
}
float PositionComponent::Height() noexcept {
    return height;
}   

void PositionComponent::SetShape(float w, float h) {
    width = w;
    height = h;
}