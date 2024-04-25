#include <time/time.hpp>

FPSController::FPSController() noexcept {
    frameStart = SDL_GetTicks();
}

FPSController::~FPSController() noexcept {
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }   
}