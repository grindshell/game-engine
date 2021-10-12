#ifndef ACTOR_H
#define ACTOR_H
class Actor {
    int x = 0;
    int y = 0;
    int height = 0;
    int width = 0;
public:
    Actor(int x, int y, int height, int width);

    void set_pos(int x, int y);
    void set_height(int width);
    void set_width(int height);
    std::string to_string();
};
#endif
