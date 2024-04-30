#include <menu/menu.hpp>
#include <ECS/ECS.hpp>
#include <components/components.hpp>
#include <utilities/utilities.hpp>

Menu::Menu(std::shared_ptr<Game> game_, SDL_Window* window_, SDL_Renderer* renderer_) : 
    game(game_), window(window_), renderer(renderer_) {
}

Entity mouse;
Entity background;
Entity base;
Entity launcher;
Entity meteor;
SDL_Event event;

void Menu::Run() {
    mouse.AddComponent<PositionComponent>(0,0,45,45);
    mouse.AddComponent<Mouse>(ShortNames::scope);
    mouse.GetComponent<Mouse>().SetBoarders(0,0,15,15);

    background.AddComponent<PositionComponent>(0,0,1080,720);
    background.AddComponent<SimpleTexture>(ShortNames::back);
    background.GetComponent<SimpleTexture>().SetBoarders(0,0,1920,1080);

    base.AddComponent<PositionComponent>(31,610,132,66);
    base.AddComponent<SimpleTexture>(ShortNames::base);
    base.GetComponent<SimpleTexture>().SetBoarders(0,0,22,11);

    launcher.AddComponent<PositionComponent>(70,550,55,100);
    launcher.AddComponent<Follower>(ShortNames::launcher);
    launcher.GetComponent<Follower>().SetCenter(27, 75);
    launcher.GetComponent<Follower>().SetBoarders(0,0,11,20);
    
    launcher.AddComponent<Shooter>(ShortNames::bullet, 1);
    launcher.GetComponent<Shooter>().SetSrc(0,0,9,18);
    launcher.GetComponent<Shooter>().SetCenter(9,75);

    meteor.AddComponent<PositionComponent>(500, 100, 55,95);
    meteor.AddComponent<AnimatedTexture>(ShortNames::animatedMeteor);
    meteor.GetComponent<AnimatedTexture>().AddAnimation("fall", 0, 4, 150);
    meteor.GetComponent<AnimatedTexture>().SetBoarders(0,0,11,19);
    meteor.GetComponent<AnimatedTexture>().Play("fall");

    while (game->inMenu) {
        std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();
        SDL_PollEvent(&event);
        if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            launcher.GetComponent<Shooter>().Shoot();
        }
        Update();
        Render();
    }
}


void Menu::Update() {
    meteor.Update();
    base.Update();
    launcher.Update();

    mouse.Update();
}

void Menu::Render() {
    SDL_RenderClear(renderer);

    // background.Draw();
    meteor.Draw();
    launcher.Draw();
    base.Draw();

    mouse.Draw();
    SDL_RenderPresent(renderer);
}