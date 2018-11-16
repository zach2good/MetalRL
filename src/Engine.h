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
    std::shared_ptr<Map> map;
    std::shared_ptr<Log> log;

    enum State
    {
        Freeroam,
        Battle_PlayerTurn,
        Battle_EnemyTurn,
        PlayerDead
    };
    State state;
};