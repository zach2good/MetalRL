#pragma once

#include "common.h"

class Actor {
public :
    int x;
    int y;
    int ch;
    TCODColor col;

    Actor(int x, int y, int ch, const TCODColor &col);
    void render() const;
};
