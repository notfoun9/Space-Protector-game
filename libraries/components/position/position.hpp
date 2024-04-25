#pragma once 

#include <ECS/ECS.hpp>


class PositionComponent : public Component {
public:
    int X() noexcept;
    int Y() noexcept;

    void SetPos(int x, int y); 
    void Move(int x, int y);

    void Init() noexcept override;
private:
    int xPos = 0;
    int yPos = 0;
} ;