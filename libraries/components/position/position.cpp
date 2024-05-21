#include <position/position.hpp>
#include <Vector2D/Vector2D.hpp>

struct PositionComponent::Impl {
    Impl() = default;
    ~Impl() = default;
    Impl(const Impl& rhs) = default;
    Impl(Impl&& rhs) = default;
    Impl& operator=(const Impl& rhs) = default;
    Impl& operator=(Impl&& rhs) = default;
    
    
    Vector2D velocity;
    Vector2D acceleration = {0,0};
    Vector2D position;

    float width = 32;
    float height = 32;

    float scale = 1;

    float speed = 0;

} ;

PositionComponent::PositionComponent() noexcept {
    pimpl = std::make_unique<Impl>();
}

PositionComponent::PositionComponent(float x, float y) noexcept{
    pimpl = std::make_unique<Impl>();
    pimpl->position.x = x;
    pimpl->position.y = y;
}
PositionComponent::PositionComponent(float x, float y, float w, float h) noexcept  {
    pimpl = std::make_unique<Impl>();
    pimpl->position.x = x;
    pimpl->position.y = y;
    pimpl->width = w;
    pimpl->height = h;
}

PositionComponent::~PositionComponent() = default;
PositionComponent::PositionComponent(PositionComponent&& rhs) = default;
PositionComponent& PositionComponent::operator=(PositionComponent&& rhs) = default;
PositionComponent& PositionComponent::operator=(const PositionComponent& rhs) {
    auto pimpl2 = std::make_unique<Impl>(*rhs.pimpl);
    pimpl = std::move(pimpl2);
    return *this;
}
PositionComponent::PositionComponent(const PositionComponent& rhs) {
    auto pimpl2 = std::make_unique<Impl>(*rhs.pimpl);
    pimpl = std::move(pimpl2);
}

void PositionComponent::Update() {
    if (pimpl->speed != 0) {
        pimpl->position += pimpl->velocity * pimpl->speed;
    }
    if (pimpl->acceleration.Mod() != 0) {
        pimpl->velocity.x += pimpl->acceleration.x;
        pimpl->velocity.y += pimpl->acceleration.y;
    }
}

float PositionComponent::X() noexcept {
    return pimpl->position.x;
}
float PositionComponent::Y() noexcept {
    return pimpl->position.y;
}

void PositionComponent::SetPos(float x, float y) {
    pimpl->position.x = x;
    pimpl->position.y = y;
}
 
float PositionComponent::Width() noexcept {
    return pimpl->width;
}
float PositionComponent::Height() noexcept {
    return pimpl->height;
}   

void PositionComponent::SetShape(float w, float h) {
    pimpl->width = w;
    pimpl->height = h;
}

void PositionComponent::SetVelocity(int x, int y) { 
    pimpl->velocity.x = x; 
    pimpl->velocity.y = y; 
} 

void PositionComponent::SetAcceleration(float x, float y) { 
    pimpl->acceleration.x = x; 
    pimpl->acceleration.y = y; 
} 

void PositionComponent::SetSpeed(const float speed_) { 
    pimpl->speed = speed_; 
}