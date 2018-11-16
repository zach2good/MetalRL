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

    // Gerblins
    tiles[20 + (10 * height)].creature = std::make_shared<Actor>("Goblin", 20, 10, 'g', "green");
    tiles[21 + (11 * height)].creature = std::make_shared<Actor>("Goblin", 21, 11, 'g', "green");
    tiles[21 + (14 * height)].creature = std::make_shared<Actor>("Goblin", 21, 14, 'g', "green");
}

void Map::step(std::shared_ptr<Log> log)
{
    for(auto& tile : tiles)
    {
        if(tile.creature && !tile.creature->alive)
        {
            log->alert(tile.creature->name + " has died!");

            // Downcast into renderable base class
            tile.object = tile.creature;
            // Destroy creature
            tile.creature = nullptr;
        }
    }
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
        if(tile.creature)
        {
            terminal_color(tile.creature->color);
            terminal_put(tile.creature->x, tile.creature->y, tile.creature->ch);
        }
        if (tile.object)
        {
            terminal_color(tile.object->color);
            terminal_put(tile.object->x, tile.object->y, tile.object->ch);
        }
    }
}

bool Map::isWall(int x, int y)
{
    return tiles[x + (y * height)].isWall();
}

bool Map::isCreature(int x, int y)
{
    return tiles[x + (y * height)].isCreature();
}