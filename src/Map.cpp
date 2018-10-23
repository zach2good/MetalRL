#include "Map.h"
#include "common.h"

Map::Map(int width, int height) : width(width), height(height), tiles(height, std::vector<Tile>(width))
{
    setWall(50,22);
}

Map::~Map() {
}

bool Map::isWall(int x, int y) const {
    return !tiles[y][x].canWalk;
}

void Map::setWall(int x, int y) {
    tiles[y][x].canWalk = false;
}

void Map::render() const {
    for (int y=0; y < height; ++y) {
        for (int x=0; x < width; ++x) {
            TCODConsole::root->setCharBackground(x,y,
                                                  isWall(x,y) ? darkWall : darkGround );
        }
    }
}