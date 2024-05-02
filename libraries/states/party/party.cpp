#include <party/party.hpp>
#include <ECS/ECS.hpp>
#include <components/components.hpp>
#include <utilities/utilities.hpp>

Party::Party(std::shared_ptr<Game> game_, SDL_Renderer* renderer_) : 
    game(game_), renderer(renderer_) {
}

Entity mouse;
Entity background;
Entity lifes;
Entity base;

Entity launcher;

Entity spawner;
SDL_Event event;


void Party::Run() {
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
    
    enum settings {METEOR_SIZE_MIN, METEOR_SIZE_MAX, METEOR_FREQUENCY, METEOR_SPEED, METEOR_NUM, BUL_SIZE, BUL_NUM, METEOR_ACCELERATION, LIFES};
    game->settings = {5, 6, 3000, 2, 20, 4, 4, 3, 5};

    launcher.AddComponent<Shooter>(ShortNames::bullet, 10);
    launcher.GetComponent<Shooter>().SetSrc(0,0,9,18);
    launcher.GetComponent<Shooter>().SetSize(get<BUL_SIZE>(game->settings));
    launcher.GetComponent<Shooter>().AddBullets(get<BUL_NUM>(game->settings));

    spawner.AddComponent<Spawner>(get<METEOR_FREQUENCY>(game->settings));
    spawner.GetComponent<Spawner>().Start();
    spawner.GetComponent<Spawner>().SeBoarders(200, 900);
    spawner.GetComponent<Spawner>().SetSize(get<METEOR_SIZE_MIN>(game->settings), get<METEOR_SIZE_MAX>(game->settings));
    spawner.GetComponent<Spawner>().SetVelocity(0, get<METEOR_SPEED>(game->settings));
    spawner.GetComponent<Spawner>().AddMeteors(get<METEOR_NUM>(game->settings));
    spawner.GetComponent<Spawner>().SetSpeed(2);

    while (game->inParty) {
        std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();
        SDL_PollEvent(&event);
        if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            launcher.GetComponent<Shooter>().Shoot();
        }

        Update();
        Render();
    }
}


void Party::Update() {
    base.Update();
    launcher.Update();
    spawner.Update();
    mouse.Update();

    if (launcher.HasComponent<BulletsCollider>() == 0) return;

    BulletHitbox* aboba;

    auto* meteors = spawner.GetComponent<Spawner>().GetMeteors()->GetEntities();
    for (auto& met : *meteors) {
        aboba = (launcher.GetComponent<BulletsCollider>().DoesCollide((*met).GetComponent<MeteorHitbox>().GetBox()));
        if (aboba) {
            std::cout << "sec" << '\n';
            aboba->DestroyOwner();
            met->Destroy();
            return;
        }
    }
}

void Party::Render() {
    SDL_RenderClear(renderer);

    // background.Draw();
    spawner.Draw();
    launcher.Draw();
    launcher.GetComponent<Follower>().Draw();
    base.Draw();

    mouse.Draw();
    SDL_RenderPresent(renderer);

}