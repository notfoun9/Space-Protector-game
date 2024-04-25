#include <position/position.hpp>

int PositionComponent::X() noexcept {
    return xPos;
}
int PositionComponent::Y() noexcept {
    return xPos;
}

void PositionComponent::SetPos(int x, int y) {
    xPos = x;
    yPos = y;
}

void PositionComponent::Move(int x, int y) {
    xPos += x;
    yPos += y;
}

void PositionComponent::Init() noexcept {
    xPos = 0;
    yPos = 0;
}