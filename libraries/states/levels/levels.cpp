#include <levels/levels.hpp>
#include <position/position.hpp>
#include <text/text.hpp>
#include <utilities/utilities.hpp>
#include <components/components.hpp>

Levels::Levels(Game* game_, SDL_Renderer* renderer_) : game(game_), renderer(renderer_) {

    auto* level0Button = &buttons.AddEntity();
    buts.push_back(level0Button);
    auto* level1Button = &buttons.AddEntity();
    buts.push_back(level1Button);
    auto* level2Button = &buttons.AddEntity();
    buts.push_back(level2Button);
    auto* level3Button = &buttons.AddEntity();
    buts.push_back(level3Button);
    auto* level4Button = &buttons.AddEntity();
    buts.push_back(level4Button);
    auto* level5Button = &buttons.AddEntity();
    buts.push_back(level5Button);
    auto* level6Button = &buttons.AddEntity();
    buts.push_back(level6Button);
    auto* level7Button = &buttons.AddEntity();
    buts.push_back(level7Button);

    int pos = -40;
    for (auto& b : buts) {
        b->AddComponent<PositionComponent>(100, pos += 70, 865, 60);
        b->AddComponent<Button>(ShortNames::activeButton, ShortNames::button);
        b->GetComponent<Button>().SetDiff(-15,0);
        b->AddComponent<Text>(ShortNames::font, 50, SDL_Color{0,0,0,255});
    }
    buts[0]->GetComponent<Text>().SetMessage("Level 1: Easy Start");
    buts[1]->GetComponent<Text>().SetMessage("Level 2: Make it Faster!");
    buts[2]->GetComponent<Text>().SetMessage("Level 3: Hurry up!");
    buts[3]->GetComponent<Text>().SetMessage("Level 4: New Conditions");
    buts[4]->GetComponent<Text>().SetMessage("Level 5: Stressful situation");
    buts[5]->GetComponent<Text>().SetMessage("Level 6: Kill the insect");
    buts[6]->GetComponent<Text>().SetMessage("Level 7: A long night");
    buts[7]->GetComponent<Text>().SetMessage("Level 8: CHAOS EVERYWHERE");
}

void Levels::Run() {

    SDL_ShowCursor(true);
    while (game->inMenu) {
        std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();
        Update();
        Render();
    }
}

/*
level_0 : easy start       (fast bullets, medium-sized meteors, medium-speed meteors)
level_1 : make it faster   (fast bullets, medium-sized meteors, fast-speed meteors)
level_2 : hurry up!        (fast bullets, small-sized meteors, fast-speed meteors)
level_3 : new conditions   (angles added)
level_4 : stressful game   (small amount of bullets)
level_5 : kill the insect  (very small meteors)
level_6 : a long night     (a lot of meteors to destroy)
level_7 : CHAOS EVERYWHERE (angles, fast meteost, small sizes)
*/

void Levels::Update() {
    buttons.Update();
    SDL_Event e;
    SDL_PollEvent(&e);
    if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
        for (int i = 0; i < buts.size(); ++i) {
            if (buts[i]->GetComponent<Button>().IsSelected()) {
                std::cout << "Level " << i << "is started" << '\n';
                game->settings = game->lvls[i];
                game->inMenu = 0;
                game->inParty = 1;
                return;
            }
        }
    }
    // const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    // if (keystates[SDL_SCANCODE_ESCAPE]) {
    //     game->inMenu = 0;
    //     game->IsRunning() = 0;
    // }

}

void Levels::Render() {
    SDL_RenderClear(renderer);
    buttons.Draw();

    SDL_RenderPresent(renderer);
}
