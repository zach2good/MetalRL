#pragma once

#include "common.h"

struct Tile
{
    bool isWall = false;
};

struct Map
{
    Map(int w, int h)
    : width(w)
    , height(h)
    , tiles(w * h)
    {
        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                if (i == 0 || i == width -1 || j == 0 || j == height - 1) tiles[i + (j * height)].isWall = true;
            }
        }
    }

    void render() const
    {
        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                Tile tile = tiles[i + (j * height)];
                if (tile.isWall)
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
    }

    bool isWall(int x, int y) const
    {
        return tiles[x + (y * height)].isWall;
    }

    int width;
    int height;
    std::vector<Tile> tiles;
};

struct Actor
{
    Actor(int x, int y, int ch, const char* col)
    : x(x), y(y), ch(ch), col(col), ac(10), toHit(3)
    {

    }

    void render() const
    {
        terminal_color(col);
        terminal_put(x, y, ch);
    }

    void attack(Actor& other)
    {
        // roll to hit
        int toHitResult = 10 + toHit;
        if (!(toHitResult >= other.ac)) return;

        // roll damage;
        int damageRoll = 4;

        other.hp -= damageRoll;

        std::cout << toHitResult << " to hit, for " << damageRoll << " damage. Target's hp: " << other.hp << std::endl;
    }

    int x;
    int y;
    int ch;
    const char* col;

    // battle stats
    int ac;
    int toHit;
    int hp = 10;
};

struct Log
{
    void render() const
    {
        int counter = (messages.size() < 7) ? messages.size() : 7;
        for (int i = 1; i < counter; ++i) {
            terminal_color(color_from_argb(255/i, 255, 255, 255));
            terminal_print(15, 49 - i, messages[(messages.size() - 1 - i)].data());
        }
    }
    std::vector<std::string> messages;
};

class Engine
{
public:
    Engine();
    ~Engine();

    void step();
    void render() const;

    inline bool isRunning() { return running; }

private:
    bool running = true;

    Actor player;
    Actor goblin;
    Map map;
    Log log;

    bool isGoblin(int x, int y)
    {
        return x == goblin.x && y == goblin.y;
    }
};