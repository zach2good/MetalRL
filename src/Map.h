#pragma once

#include "common.h"

struct Tile {
    bool canWalk;
    Tile() : canWalk(true) {}
};

class Map {
public :
    int width;
    int height;

    Map(int width, int height);
    ~Map();

    bool isWall(int x, int y) const;
    void render() const;

protected :
    std::vector<std::vector<Tile>> tiles;

    void setWall(int x, int y);
private:
    const TCODColor darkWall = TCODColor(0,0,100);
    const TCODColor darkGround = TCODColor(50,50,150);
};
