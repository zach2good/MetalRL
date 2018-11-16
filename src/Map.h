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

    void render() const;

    bool isWall(int x, int y);
    bool canInteract(int x, int y);

    Actor& getInteractable(int x, int y)
    {
        return tiles[x + (y * height)].interactables[0];
    }

private:
    struct Tile
    {
        bool isWall()
        {
            return feature == TileFeature::Wall;
        }

        bool canInteract()
        {
            return !interactables.empty();
        }

        TileFeature feature = TileFeature::None;

        std::vector<Actor> interactables;
    };

    int width;
    int height;
    std::vector<Tile> tiles;
};

