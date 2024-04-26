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

void Menu::Run() {
    mouse.AddComponent<PositionComponent>(0,0,45,45);
    mouse.AddComponent<SimpleTexture>(ShortNames::scope);
    mouse.GetComponent<SimpleTexture>().SetBoarders(0,0,15,15);

    background.AddComponent<PositionComponent>(0,0,1080,720);
    background.AddComponent<SimpleTexture>(ShortNames::back);
    background.GetComponent<SimpleTexture>().SetBoarders(0,0,1920,1080);

    base.AddComponent<PositionComponent>(30,610,110,55);
    base.AddComponent<SimpleTexture>(ShortNames::base);
    base.GetComponent<SimpleTexture>().SetBoarders(0,0,22,11);

    while (game->inMenu) {
        std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();
        SDL_Event event;
        SDL_PollEvent(&event);

        Update();
        Render();
    }
}


void Menu::Update() {
    background.Update();
    base.Update();



    SDL_GetMouseState(&(mouse.GetComponent<SimpleTexture>().GetDest().x), &(mouse.GetComponent<SimpleTexture>().GetDest().y));
}

void Menu::Render() {
    SDL_RenderClear(renderer);

    background.Draw();
    base.Draw();
    mouse.Draw();
    SDL_RenderPresent(renderer);
}