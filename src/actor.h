#ifndef ACTOR_H
#define ACTOR_H
class Actor {
    int x = 0;
    int y = 0;
public:
    Actor(int x, int y);

    void set_xy(int x, int y);
    std::string to_string();
};
#endif
