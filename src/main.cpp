#include "Engine.h"

int main()
{
    Engine engine;

    while (engine.isRunning())
    {
        engine.step();
        engine.render();
    }

    return 0;
}