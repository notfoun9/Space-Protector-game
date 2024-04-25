#include <game/game.hpp>
#include <components/components.hpp>
#include <utilities/utilities.hpp>

SDL_Renderer* Game::renderer = nullptr;


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
    std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();

    SDL_Event event;
    SDL_PollEvent(&event);

    SDL_RenderClear(renderer);

    Entity testPic = Entity();
    testPic.AddComponent<PositionComponent>();
    testPic.GetComponent<PositionComponent>().SetPos(100,100);

    testPic.AddComponent<SimpleTexture>(ShortNames::testTex);
    testPic.GetComponent<SimpleTexture>().SetBoarders(0,0,100,100);
    testPic.GetComponent<SimpleTexture>().SetShape(100,100);


    testPic.Update();
    testPic.Draw();
    
    SDL_RenderPresent(renderer);
}
