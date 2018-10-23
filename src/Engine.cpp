#include "Engine.h"

Engine::Engine() {
    TCODConsole::initRoot(100, 60, "MetalRL" ,false);
}

Engine::~Engine() = default;

void Engine::update() {
    TCOD_key_t key;
    TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,nullptr);
    switch(key.vk) {
        case TCODK_UP :
            break;
        case TCODK_DOWN :
            break;
        case TCODK_LEFT :
            break;
        case TCODK_RIGHT :
            break;
        default:break;
    }
}

void Engine::render() {
    TCODConsole::root->clear();
}