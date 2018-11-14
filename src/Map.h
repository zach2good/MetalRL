#pragma once

#include "common.h"
#include "BearLibTerminal.h"

enum TileFeature
{
    None,
    Wall,
    Hole
};
class Map
{
public:
    Map(int w, int h);

    void render() const;

    bool isWall(int x, int y);

private:
    struct Tile
    {
        TileFeature feature = TileFeature::None;

        std::vector<GameObject> objects;

        bool isWall()
        {
            return feature == TileFeature::Wall;
        }
    };

    int width;
    int height;
    std::vector<Tile> tiles;
};

