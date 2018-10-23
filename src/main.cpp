#include "Engine.h"

int main()
{
    Engine engine;
    while (!TCODConsole::isWindowClosed())
    {
        engine.update();
        engine.render();
        TCODConsole::flush();
    }
    return 0;
}