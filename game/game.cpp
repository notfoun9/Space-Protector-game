#include <game/game.hpp>
#include <components/components.hpp>
#include <utilities/utilities.hpp>
#include <party/party.hpp>
#include <levels/levels.hpp>

SDL_Renderer* Game::renderer = nullptr;



SDL_Event Game::event;
Game::~Game() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    SDL_DestroyRenderer(Game::renderer);
    SDL_DestroyWindow(window);
}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        std::cout << "seccess" <<'\n';
        isRunning = true;
    }
    else {
        std::cerr << "fail" <<'\n';
        isRunning = false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "failed to init ttf" << '\n';
        return;
    }

    Life::Init();
}

bool& Game::IsRunning() {
    return isRunning;
}
void Game::ToggleFullscreen() {
    static int64_t lastUsed = 0;
    if (SDL_GetTicks64() - lastUsed > 500) {
        lastUsed = SDL_GetTicks64();
        fullscreen_ = !fullscreen_;
        (fullscreen_) ? SDL_SetWindowFullscreen(window, 1) : SDL_SetWindowFullscreen(window, 0);
    }
}
void Game::Quit() {
    isRunning = 0;
}

void Game::Run() {
    Party party(this, renderer);
    Levels levels(this, renderer);
    while (IsRunning()) {
        if (inMenu) {
            std::cout << "InMenu" << '\n';
            levels.Run();
        }
        if (inParty) {
            std::cout << "inParty" << '\n';
            party.Run();
        }
    }
}