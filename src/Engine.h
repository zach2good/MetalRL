#pragma once

#include "common.h"
#include "Map.h"
#include "Log.h"
#include "Actor.h"

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

    std::shared_ptr<Actor> player;
    std::vector<Actor> actors;
    Map map;
    Log log;
};