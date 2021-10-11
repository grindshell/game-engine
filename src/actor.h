#ifndef ACTOR_H
#define ACTOR_H
class Actor {
    int x = 0;
    int y = 0;
public:
    Actor() = default;

    void setXY(int x, int y);
};
#endif
