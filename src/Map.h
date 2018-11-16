#pragma once

#include "common.h"
#include "BearLibTerminal.h"

enum TileFeature
{
    None,
    Wall
};

class Map
{
public:
    Map(int w, int h);

    void step(std::shared_ptr<Log> log);
    void render() const;

    bool isWall(int x, int y);
    bool isCreature(int x, int y);
    std::shared_ptr<Actor> getCreature(int x, int y)
    {
        return tiles[x + (y * height)].creature;
    }

private:
    struct Tile
    {
        bool isWall()
        {
            return feature == TileFeature::Wall;
        }

        bool isCreature()
        {
            return creature == nullptr;
        }

        TileFeature feature = TileFeature::None;
        std::shared_ptr<Actor> creature = nullptr;
        std::shared_ptr<GameObject> object = nullptr;
    };

    int width;
    int height;
    std::vector<Tile> tiles;
};

