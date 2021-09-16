#ifndef GAME_CORE_H
#define GAME_CORE_H
class GameCore {
    bool running = false;
public:
    GameCore() = default;
    void run();
};
#endif
