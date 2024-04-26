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


float PositionComponent::X() noexcept {
    std::cout << "entered" << '\n';
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