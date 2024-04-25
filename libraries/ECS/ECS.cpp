#include <ECS/ECS.hpp>

class PositionComponent;
void Entity::Update() {
    for (auto& comp : components) {
        comp->Update();
    }
}

void Entity::Draw() {
    for (auto& comp : components) {
        comp->Draw();
    }
}

void Entity::Destroy() {
    active = false;
}

bool Entity::IsActive() {
    return active;
}

void Manager::Update() {
    for (auto& e : entities) {
        e->Update();
    }
}

void Manager::Draw() {
    for (auto& e : entities) {
        e->Draw();
    }
}

void Manager::Refresh() {
    entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
        [](const std::unique_ptr<Entity> &mEntity) { 
            return !mEntity->IsActive(); 
        } ), 
        std::end(entities));
}

Entity& Manager::AddEntity() {
    Entity* e = new Entity();
    std::unique_ptr<Entity> uPtr { e };
    entities.emplace_back(std::move(uPtr));
    
    return *e;
}
