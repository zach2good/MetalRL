#pragma once

#include "common.h"

class Engine
{
public:
    Engine();
    ~Engine();

    void step();
    void render() const;

    inline bool isCloseRequested() { return closeRequested; }

private:
    bool closeRequested = false;
};