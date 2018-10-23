#include "Engine.h"
#include "version.h"

Engine::Engine()
{
    TCODConsole::initRoot(100, 60, "MetalRL", false);
    x = 15;
    y = 15;
}

Engine::~Engine() = default;

void Engine::update()
{
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);
    switch (key.vk)
    {
    case TCODK_UP:
        y--;
        break;
    case TCODK_DOWN:
        y++;
        break;
    case TCODK_LEFT:
        x--;
        break;
    case TCODK_RIGHT:
        x++;
        break;
    default:
        break;
    }
}

void Engine::render()
{
    TCODConsole::root->clear();

    TCODConsole::root->printf(10, 10, "Hello MetalRL");
    TCODConsole::root->printf(10, 10, "Arrow keys to move...");
    TCODConsole::root->putChar(x, y, '@');

    TCODConsole::root->printf(0, 0, "GIT_BRANCH: " GIT_BRANCH);
    TCODConsole::root->printf(0, 1, "GIT_COMMIT_HASH: " GIT_COMMIT_HASH);
    TCODConsole::root->printf(0, 2, "GIT_DATE: " GIT_DATE);
    TCODConsole::root->printf(0, 3, "GIT_COMMIT_SUBJECT: " GIT_COMMIT_SUBJECT);
    TCODConsole::root->printf(0, 4, "BUILD_DATE: " BUILD_DATE);
}