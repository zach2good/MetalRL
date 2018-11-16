#include "Engine.h"
#include "version.h"

constexpr int ScreenWidth = 80;
constexpr int ScreenHeight = 30;

Engine::Engine()
: map(80, 50)
{
    terminal_open();

    terminal_set("window: title='MetalRL', resizeable=false, size=80x30");
    terminal_set("input.filter={keyboard, mouse+}, precise-mouse=true");
    terminal_composition(TK_ON);
    terminal_bkcolor("black");

    player = std::make_shared<Actor>("Player", 10, 10, '@', "white");
    player->setLog(&log);
}

Engine::~Engine()
{
    terminal_close();
}

void Engine::step()
{
    if (!player->alive) return;

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
                if(map.canInteract(player->x, player->y - 1))
                {
                    auto act = map.getInteractable(player->x, player->y - 1);
                    player->attack(act);
                }
                if (map.isWall(player->x, player->y - 1))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player->y--;
                break;
            }
            case TK_DOWN: {
                keyPressed = true;
                if (map.isWall(player->x, player->y + 1))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player->y++;
                break;
            }
            case TK_LEFT: {
                keyPressed = true;
                if (map.isWall(player->x - 1, player->y))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player->x--;
                break;
            }
            case TK_RIGHT: {
                keyPressed = true;
                if (map.isWall(player->x + 1, player->y))
                {
                    log.messages.push_back("You walk into a wall!");
                    break;
                }
                player->x++;
                break;
            }
            default:
                break;
        }
    }

    // Only update game logic on keypress
    if (!keyPressed) return;

    for (Actor& actor : actors)
    {
        if (actor.alive && actor.inRange(*player))
        {
            actor.attack(*player);
        }
    }
}

void Engine::render() const
{
    terminal_clear();

    map.render();

    terminal_printf(2, 23, "[color=orange]ESC.[/color] Exit");

    for (const Actor& actor : actors)
    {
        actor.render();
    }

    player->render();

    log.render();

    terminal_refresh();
}
