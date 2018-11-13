#include "Engine.h"
#include "version.h"

constexpr int ScreenWidth = 80;
constexpr int ScreenHeight = 50;

Engine::Engine()
: map(80, 50)
, player(10, 10, '@', "white")
, goblin(20, 10, 'g', "green")
{
    terminal_open();

    terminal_set("window: title='MetalRL', resizeable=false, size=80x50");
    terminal_set("input.filter={keyboard, mouse+}, precise-mouse=true");
    terminal_composition(TK_ON);
    terminal_bkcolor("black");

    player.ac = 12;
    player.toHit = 4;
}

Engine::~Engine()
{
    terminal_close();
}

void Engine::step()
{
    // Handle Input
    bool keyPressed = false;
    if (terminal_has_input()) {
        int key = terminal_read();
        //log.messages.push_back(to_string(key));
        switch(key){
            case TK_ESCAPE: {
                running = false;
                break;
            }
            case TK_UP: {
                keyPressed = true;
                if (isGoblin(player.x, player.y - 1))
                {
                    log.messages.push_back("Oh no! A Goblin!");
                    player.attack(goblin);
                    break;
                }
                if (map.isWall(player.x, player.y - 1))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player.y--;
                break;
            }
            case TK_DOWN: {
                keyPressed = true;
                if (isGoblin(player.x, player.y + 1)) {
                    log.messages.push_back("Oh no! A Goblin!");
                    player.attack(goblin);
                    break;
                }
                if (map.isWall(player.x, player.y + 1))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player.y++;
                break;
            }
            case TK_LEFT: {
                keyPressed = true;
                if (isGoblin(player.x - 1, player.y)) {
                    log.messages.push_back("Oh no! A Goblin!");
                    player.attack(goblin);
                    break;
                }
                if (map.isWall(player.x - 1, player.y))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player.x--;
                break;
            }
            case TK_RIGHT: {
                keyPressed = true;
                if (isGoblin(player.x + 1, player.y)) {
                    log.messages.push_back("Oh no! A Goblin!");
                    player.attack(goblin);
                    break;
                }
                if (map.isWall(player.x + 1, player.y))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player.x++;
                break;
            }
            default:
                break;
        }
    }

    // Only update game logic on keypress
    if (!keyPressed) return;
}

void Engine::render() const
{
    terminal_clear();

    map.render();

    terminal_printf(2, 23, "[color=orange]ESC.[/color] Exit");

    goblin.render();
    player.render();

    log.render();

    terminal_refresh();
}
