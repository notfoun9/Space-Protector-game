#include <levels/levels.hpp>

Levels::Levels(std::shared_ptr<Game> game_, SDL_Renderer* renderer_) : game(game_), renderer(renderer_) {



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