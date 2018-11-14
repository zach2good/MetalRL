//
// Created by Zach Toogood on 13/11/2018.
//

#pragma once

#include "common.h"
#include "Log.h"

class Actor
{
public:
    Actor(const char* name, int x, int y, int ch, const char* col)
    : name(name), x(x), y(y), ch(ch), col(col)
    {

    }

    void setLog(Log* l)
    {
        log = l;
    }

    void render() const
    {
        terminal_color(col);
        terminal_put(x, y, ch);
    }

    void attack(Actor& other)
    {
        std::string out;
        out = name + "(" + to_string(hp) + "hp): ";

        // roll to hit
        int roll = r.roll(dice::d20);
        int toHitResult = roll + toHit;
        out += to_string(toHitResult) + " to hit. ";
        if (toHitResult >= other.ac)
        {
            // roll damage;
            int damageRoll = r.roll(dice);

            if (roll == 20) damageRoll *= 2;

            other.hp -= damageRoll;
            out += to_string(damageRoll) + " damage. ";

            if (other.hp <= 0)
            {
                other.col = "red";
                other.alive = false;
                out += other.name + " has died!";
            }
        }
        log->messages.push_back(out);
    }

    int distanceTo(Actor& other)
    {
        auto _x = pow(x - other.x, 2);
        auto _y = pow(y - other.y, 2);
        return static_cast<int>(sqrt(_x + _y));
    }

    bool inRange(Actor& other)
    {
        return distanceTo(other) <= range;
    }

    std::string name;
    int x;
    int y;
    int ch;
    const char* col;

    // battle stats
    int ac = 10;
    int toHit = 0;
    dice dice = dice::d4;
    int hp = 10;
    int range = 1;
    bool alive = true;

    roller r;

    Log* log;
};



