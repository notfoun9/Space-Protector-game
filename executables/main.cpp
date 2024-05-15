#include <game/game.hpp>


int main() {

    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->Init("Secret Stones", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, false);
    SDL_ShowCursor(false);

    if (!game) std::cout << "error 1" << '\n';
    if (game->IsRunning()) {
        game->Run();
    }
    std::cout << "Flag 1" << '\n';
    game->Quit();

    return 0;
}