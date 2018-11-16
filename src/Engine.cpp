#include "Engine.h"
#include "version.h"

constexpr int ScreenWidth = 80;
constexpr int ScreenHeight = 30;

Engine::Engine()
: map(std::make_shared<Map>(80, 50))
, log(std::make_shared<Log>())
, state(Battle_PlayerTurn)
{
    terminal_open();

    terminal_set("window: title='MetalRL', resizeable=false, size=80x30");
    terminal_set("input.filter={keyboard, mouse+}, precise-mouse=true");
    terminal_composition(TK_ON);
    terminal_bkcolor("black");

    player = std::make_shared<Actor>("Player", 10, 10, '@', "white");
}

Engine::~Engine()
{
    terminal_close();
}

void Engine::step()
{
    // Map Cleanup
    map->step(log);

    switch(state)
    {
        case Freeroam:
        {
            break;
        }
        case Battle_EnemyTurn:
        {
            break;
        }
        case Battle_PlayerTurn:
        {
            // Handle Input
            if (terminal_has_input()) {
                int key = terminal_read();
                switch(key){
                    case TK_ESCAPE: {
                        running = false;
                        break;
                    }
                    case TK_UP: {
                        if(auto creature = map->getCreature(player->x, player->y - 1))
                        {
                            player->attack(creature, log);
                            break;
                        }
                        if (map->isWall(player->x, player->y - 1))
                        {
                            log->message("You walk into a wall!");
                            break;
                        }
                        player->y--;
                        break;
                    }
                    case TK_DOWN: {
                        if(auto creature = map->getCreature(player->x, player->y + 1))
                        {
                            player->attack(creature, log);
                            break;
                        }
                        if (map->isWall(player->x, player->y + 1))
                        {
                            log->message("You walk into a wall!");
                            break;
                        }
                        player->y++;
                        break;
                    }
                    case TK_LEFT: {
                        if(auto creature = map->getCreature(player->x - 1, player->y))
                        {
                            player->attack(creature, log);
                            break;
                        }
                        if (map->isWall(player->x - 1, player->y))
                        {
                            log->message("You walk into a wall!");
                            break;
                        }
                        player->x--;
                        break;
                    }
                    case TK_RIGHT: {
                        if(auto creature = map->getCreature(player->x + 1, player->y))
                        {
                            player->attack(creature, log);
                            break;
                        }
                        if (map->isWall(player->x + 1, player->y))
                        {
                            log->message("You walk into a wall!");
                            break;
                        }
                        player->x++;
                        break;
                    }
                    default:
                        break;
                }
            }
            break;
        }
        case PlayerDead:
        {
            break;
        }
    }

    for (Actor& actor : actors)
    {
        actor.step(log);

        if (actor.alive && actor.inRange(player))
        {
            actor.attack(player, log);
        }
    }
}

void Engine::render() const
{
    terminal_clear();

    map->render();

    for (const Actor& actor : actors)
    {
        actor.render();
    }

    player->render();

    log->render();

    terminal_refresh();
}
