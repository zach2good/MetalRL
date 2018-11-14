#pragma once

#include "common.h"
#include "BearLibTerminal.h"

class Map
{
public:
    Map(int w, int h);

    void render() const;

    bool isWall(int x, int y) const;

private:
    struct Tile
    {
        bool isWall = false;
    };

    int width;
    int height;
    std::vector<Tile> tiles;
};

