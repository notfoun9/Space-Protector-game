#pragma once

#include <chrono>

class FPSController {
public:
    FPSController(size_t fps);
    ~FPSController() = default;

    void EndFrame();
private:
    size_t fps;
    size_t frameDurationNs;

    std::chrono::time_point<
        std::chrono::steady_clock> lastFrame;
};
