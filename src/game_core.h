#include <list>

#include "actor.h"

#ifndef GAME_CORE_H
#define GAME_CORE_H
class GameCore {
    bool running = false;
    std::list<Actor> actors;
public:
    GameCore() = default;
    void run();
    void setActors(std::list<Actor> actors);
};
#endif
