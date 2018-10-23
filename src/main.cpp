#include "Engine.h"

int main()
{
    Engine engine;
    while (!TCODConsole::isWindowClosed())
    {
        engine.update();
        engine.render();
    }
    return 0;
}
