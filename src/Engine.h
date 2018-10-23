#pragma once

#include "common.h"

class Actor;
class Map;

class Engine
{
public:
    Engine();
    ~Engine();
    void update();
    void render();

    inline bool isWindowClosed() { return TCODConsole::isWindowClosed(); }

private:
    TCODList<std::shared_ptr<Actor>> actors;
    std::shared_ptr<Actor> player;
    std::shared_ptr<Map> map;
};
