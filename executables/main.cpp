#include <game/game.hpp>

int main() {
    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->Init("Secret Stones", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, false);
    SDL_HideCursor();

    if (game->IsRunning()) {
        game->Run();
    }
    game->Quit();

    return 0;
}
