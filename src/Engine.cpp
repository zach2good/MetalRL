#include "Engine.h"
#include "version.h"

constexpr int ScreenWidth = 80;
constexpr int ScreenHeight = 50;

Engine::Engine()
{
    terminal_open();

    // Terminal settings
    terminal_set("window: title='Rogue River: Obol of Charon', resizeable=false, minimum-size=80x50");
    //terminal_set("font: graphics/VeraMono.ttf, size=8x16");
    terminal_set("input.filter={keyboard, mouse+}, precise-mouse=true");
    terminal_composition(TK_ON);
    terminal_bkcolor("black");
}

Engine::~Engine()
{
    terminal_close();
}

void Engine::step()
{
    // Handle Input
    int key = terminal_read();
    if (key == TK_ESCAPE || key == TK_CLOSE)
    {
        closeRequested = true;
    }
}

void Engine::render() const
{
    terminal_clear();


    terminal_printf(2, 23, "[color=orange]ESC.[/color] Exit");


    terminal_refresh();
}
