#include <levels/levels.hpp>
#include <position/position.hpp>
#include <text/text.hpp>
#include <utilities/utilities.hpp>
#include <components/components.hpp>

Levels::Levels(Game* game_, SDL_Renderer* renderer_) : game(game_), renderer(renderer_) {
    int pos = -40;
    for (int i = 0; i < 8; ++i) {
        auto* levelButtonI = &buttons.AddEntity();

        levelButtonI->AddComponent<PositionComponent>(100, pos += 70, 865, 60);
        levelButtonI->AddComponent<Button>(ShortNames::activeButton, ShortNames::button);
        levelButtonI->GetComponent<Button>().SetDiff(-15,0);
        levelButtonI->AddComponent<Text>(ShortNames::font, 50, SDL_Color{0,0,0,255});

        levelButtonI->GetComponent<Text>().SetMessage("Level " + levelNames[i]);
        buts.push_back(levelButtonI);
    }
}

void Levels::Run() {
    ticksSinceJoined = SDL_GetTicks64();
    std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();
    SDL_ShowCursor(true);
    while (game->inMenu) {
        std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();
        Update();
        Render();
    }
}

void Levels::Update() {
    for (auto b : buts) {
        b->Update();
    }
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
        for (int i = 0; i < buts.size(); ++i) {
            if (buts[i]->GetComponent<Button>().IsSelected()) {
                std::cout << "Level " << i << "is started" << '\n';
                game->SetSettings(i);
                game->inMenu = 0;
                game->inParty = 1;
                return;
            }
        }
    }
    const Uint8 *keystat = SDL_GetKeyboardState(NULL);
    if (keystat[SDL_SCANCODE_ESCAPE] && (SDL_GetTicks64() - ticksSinceJoined > 500)) {
        game->inMenu = 0;
        game->Quit();
    }
    if (keystat[SDL_SCANCODE_F11]) {
        game->ToggleFullscreen();
    }

}

void Levels::Render() {
    SDL_RenderClear(renderer);
    buttons.Draw();

    SDL_RenderPresent(renderer);
}
