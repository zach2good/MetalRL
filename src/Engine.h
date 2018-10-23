#pragma once

#include "common.h"

class Engine
{
public:
    Engine();
    ~Engine();
    void update();
    void render();

private:
    int x;
    int y;
};
