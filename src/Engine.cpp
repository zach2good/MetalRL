#include "Engine.h"

#include "version.h"
#include "SDL.h"
#include "Actor.h"
#include "Map.h"

Engine::Engine()
{
    // Force shut-off SDL Logging
    SDL_LogSetOutputFunction([](void *, int, SDL_LogPriority, const char*){}, nullptr);

    TCODConsole::initRoot(100, 60, "MetalRL", false);
    player = std::make_shared<Actor>(15, 15, '@', TCODColor::yellow);
    actors.push_back(player);

    map = std::make_shared<Map>(100, 60);
}

Engine::~Engine()
{

}

void Engine::update()
{
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);
    switch (key.vk)
    {
    case TCODK_UP:
        if (!map->isWall(player->x, player->y-1)) {
            player->y--;
        }
        break;
    case TCODK_DOWN:
        if (!map->isWall(player->x, player->y+1)) {
            player->y++;
        }
        break;
    case TCODK_LEFT:
        if (!map->isWall(player->x-1, player->y)) {
            player->x--;
        }
        break;
    case TCODK_RIGHT:
        if (!map->isWall(player->x+1, player->y)) {
            player->x++;
        }
        break;
    default:
        break;
    }
}

void Engine::render()
{
    TCODConsole::root->clear();

#ifndef NDEBUG // Cmake is strange and only defines NDEBUG
    TCODConsole::root->printf(0, 0, "GIT_BRANCH: " GIT_BRANCH);
    TCODConsole::root->printf(0, 1, "GIT_COMMIT_HASH: " GIT_COMMIT_HASH);
    TCODConsole::root->printf(0, 2, "GIT_DATE: " GIT_DATE);
    TCODConsole::root->printf(0, 3, "GIT_COMMIT_SUBJECT: " GIT_COMMIT_SUBJECT);
    TCODConsole::root->printf(0, 4, "BUILD_DATE: " BUILD_DATE);
#endif

    TCODConsole::root->printf(10, 10, "Hello MetalRL");
    TCODConsole::root->printf(10, 11, "Arrow keys to move...");

    map->render();

    for (auto& actor : actors)
    {
        actor->render();
    }

    TCODConsole::flush();
}
