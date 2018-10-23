#pragma once

#include "common.h"

class Engine
{
public:
    Engine();
    ~Engine();
    void update();
    void render();

    inline bool isWindowClosed() { return TCODConsole::isWindowClosed(); }

private:
    int x;
    int y;
};
