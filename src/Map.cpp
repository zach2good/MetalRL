#include "Map.h"
#include "Actor.h"

Map::Map(int w, int h)
        : width(w)
        , height(h)
        , tiles(w * h)
{
    // Walls
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            if (i == 0 || i == width -1 || j == 0 || j == height - 1)
            {
                tiles[i + (j * height)].feature = TileFeature::Wall;
            }
        }
    }

    // Gerblin
    tiles[20 + (10 * height)].interactables.push_back(Actor("Goblin", 20, 10, 'g', "green"));
}

void Map::render() const
{
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            Tile tile = tiles[i + (j * height)];
            if (tile.isWall())
            {
                terminal_color(color_from_argb(100, 200, 200, 0));
                terminal_put(i, j, 0x2588);
            }
            else
            {
                terminal_color(color_from_argb(80, 200, 200, 100));
                terminal_put(i, j, '.');
            }

        }
    }

    for(auto& tile : tiles)
    {
        for(auto& in : tile.interactables)
        {
            in.render();
        }
    }
}

bool Map::isWall(int x, int y)
{
    return tiles[x + (y * height)].isWall();
}

bool Map::canInteract(int x, int y)
{
    return tiles[x + (y * height)].canInteract();
}