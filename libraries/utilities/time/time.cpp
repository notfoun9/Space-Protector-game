#include <time/time.hpp>
#include <thread>

FPSController::FPSController(size_t fps)
    : fps(fps)
    , frameDurationNs(1'000'000'000 / fps) 
    , lastFrame(std::chrono::steady_clock::now())
{}

void FPSController::EndFrame()
{
    auto timeSinceLastFrame = std::chrono::steady_clock::now() - lastFrame;
    auto dur = std::chrono::nanoseconds(frameDurationNs);
    if (timeSinceLastFrame < dur)
    {
        std::this_thread::sleep_for(dur - timeSinceLastFrame);
    }
    lastFrame = std::chrono::steady_clock::now();
}
