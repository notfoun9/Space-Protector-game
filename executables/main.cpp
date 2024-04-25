#include <game/game.hpp>


int main() {

    std::shared_ptr<Game> game = std::make_shared<Game>();

    game->Init("Secret Stones", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, false);
    SDL_ShowCursor(true);

    if (!game) std::cout << "error 1" << '\n';
    while (game->IsRunning()) {
        game->Run();
    }

    game->Quit();

    return 0;
}