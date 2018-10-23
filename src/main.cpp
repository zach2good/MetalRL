#include "Engine.h"

int main()
{
    Engine engine;
    while (!engine.isWindowClosed())
    {
        engine.update();
        engine.render();
    }
    return 0;
}
