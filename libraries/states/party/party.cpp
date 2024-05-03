#include <party/party.hpp>
#include <components/components.hpp>
#include <utilities/utilities.hpp>

Party::Party(Game* game_, SDL_Renderer* renderer_) : game(game_), renderer(renderer_) {
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

    launcher.AddComponent<Shooter>(ShortNames::bullet);
    launcher.GetComponent<Shooter>().SetSrc(0,0,64,128);

    bulsLeft.AddComponent<PositionComponent>(200,650,200,50);
    bulsLeft.AddComponent<Text>(ShortNames::font, 50, SDL_Color{255,255,255,0});

    spawner.AddComponent<Spawner>();
    spawner.GetComponent<Spawner>().SeBoarders(200, 900);
}



void Party::Run() {
    SDL_ShowCursor(false);
    enum settings {METEOR_SIZE_MIN, METEOR_SIZE_MAX, METEOR_FREQUENCY, METEOR_SPEED, METEOR_NUM, BUL_SIZE, BUL_NUM, BUL_SPEED, METEOR_ACCELERATION, LIFES};
    launcher.GetComponent<Shooter>().DeleteBulls();
    spawner.GetComponent<Spawner>().DeleteMets();
    
    launcher.GetComponent<Shooter>().SetSpeed(get<BUL_SPEED>(game->settings));
    launcher.GetComponent<Shooter>().SetSize(get<BUL_SIZE>(game->settings));
    launcher.GetComponent<Shooter>().AddBullets(get<BUL_NUM>(game->settings));

    spawner.GetComponent<Spawner>().SetRate(get<METEOR_FREQUENCY>(game->settings));
    spawner.GetComponent<Spawner>().Start();
    spawner.GetComponent<Spawner>().SetSize(get<METEOR_SIZE_MIN>(game->settings), get<METEOR_SIZE_MAX>(game->settings));
    spawner.GetComponent<Spawner>().SetVelocity(0, get<METEOR_SPEED>(game->settings));
    spawner.GetComponent<Spawner>().SetMeteorsNum(get<METEOR_NUM>(game->settings));
    spawner.GetComponent<Spawner>().SetSpeed(2);


    std::cout << "ABOBA" << ' ' << get<BUL_NUM>(game->settings) << '\n';

    while (game->inParty) {
        std::shared_ptr<FPSController> fpsController = std::make_shared<FPSController>();
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
            launcher.GetComponent<Shooter>().Shoot();
        }
        const Uint8 *keystat = SDL_GetKeyboardState(NULL);
        if (keystat[SDL_SCANCODE_ESCAPE]) {
            game->inParty = 0;
            game->inMenu = 1;
            std::cout << "ESC pressed" << '\n';
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
    bulsLeft.GetComponent<Text>().SetMessage("Bullets Left: ");
    bulsLeft.GetComponent<Text>().AddMessage(std::to_string(launcher.GetComponent<Shooter>().BulletsLeft()));
    bulsLeft.Update();
    if (launcher.HasComponent<BulletsCollider>() == 0) return;

    BulletHitbox* aboba;
    auto* meteors = spawner.GetComponent<Spawner>().GetMeteors()->GetEntities();
    for (auto& met : *meteors) {
        aboba = (launcher.GetComponent<BulletsCollider>().DoesCollide((*met).GetComponent<MeteorHitbox>().GetBox()));
        if (aboba) {
            aboba->DestroyOwner();
            met->Destroy();
            return;
        }
    }
}

void Party::Render() {
    SDL_RenderClear(renderer);

    background.Draw();
    spawner.Draw();
    launcher.Draw();
    launcher.GetComponent<Follower>().Draw();
    base.Draw();
    bulsLeft.Draw();

    mouse.Draw();
    SDL_RenderPresent(renderer);

}