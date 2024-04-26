#include <game/game.hpp>
#include <components/components.hpp>
#include <utilities/utilities.hpp>
#include <menu/menu.hpp>

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;
Game::Game() {


}
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
}

bool Game::IsRunning() {
    return isRunning;
}
void Game::ToggleFullscreen() {
    fullscreen_ = !fullscreen_;
    (fullscreen_) ? SDL_SetWindowFullscreen(window, 1) : SDL_SetWindowFullscreen(window, 0);
}
void Game::Quit() {
    isRunning = 0;
}

void Game::Run() {
    std::shared_ptr<Game> g { this };
    Menu menu(g , window, renderer);

    while (inMenu) {
        menu.Run();
    }
    SDL_RenderClear(renderer);
    

    SDL_RenderPresent(renderer);
}
