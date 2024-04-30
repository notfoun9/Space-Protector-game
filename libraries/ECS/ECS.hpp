#pragma once

#include <game/game.hpp>

class PositionComponent;
class SimpleTexture;
class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID GetComponentID() {
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept {
    static ComponentID typeID = GetComponentID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
public:
    Entity* owner;

    virtual void Init() {};
    virtual void Update() {};
    virtual void Draw() {};

    Component() = default;
    virtual ~Component() = default;
} ;

class Entity {
public:
    Entity() = default;
    ~Entity() = default;

    void Update();
    void Draw();
    void Destroy();

    template <typename T>
    void PrintShit(T word);

    template <typename T> bool HasComponent() const;
    template <typename T, typename...TArgs> T& AddComponent(TArgs&&... mArgs);
    template <typename T> T& GetComponent() const;
    
    bool IsActive();    

private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray compArray;
    ComponentBitSet compBitSet;

} ;

class Manager {
public:
    void Update();
    void Draw();

    void Refresh();
    void Clear();

    Entity& AddEntity();
    std::vector<std::unique_ptr<Entity>>* GetEntities() { return &entities; }
private:
    std::vector<std::unique_ptr<Entity>> entities;
} ; 


template <typename T> bool Entity::HasComponent() const {
    return compBitSet[GetComponentTypeID<T>()];
}

template <typename T, typename...TArgs> 
T& Entity::AddComponent(TArgs&&... mArgs) {
    T* t = new T(std::forward<TArgs>(mArgs)...);
    t->owner = this;
    std::unique_ptr<Component> uPtr{ t };
    
    t->Init();
    
    components.emplace_back(std::move(uPtr));

    compArray[GetComponentTypeID<T>()] = t;
    compBitSet[GetComponentTypeID<T>()] = 1;

    return *t;
}

template <typename T> T& Entity::GetComponent() const {
    auto ptr(compArray[GetComponentTypeID<T>()]);
    return *static_cast<T*>(ptr);
}

