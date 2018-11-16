//
// Created by Zach Toogood on 13/11/2018.
//

#pragma once

#include "common.h"
#include "Log.h"

class Actor : public GameObject
{
public:
    Actor(const char* name, int x, int y, int ch, const char* color)
    : name(name), GameObject(x, y, ch, color)
    {

    }

    void step(std::shared_ptr<Log> log) override
    {

    }

    void attack(std::shared_ptr<Actor> other, std::shared_ptr<Log> log)
    {
        std::string out;
        out += name + "(" + to_string(hp) + "hp): ";

        bool hit = false;

        // roll to hit
        int roll = r.roll(dice::d20);
        int toHitResult = roll + toHit;
        out += to_string(toHitResult) + " to hit. ";
        if (toHitResult >= other->ac)
        {
            hit = true;
            // roll damage;
            int damageRoll = r.roll(dice);

            if (roll == 20) damageRoll *= 2;

            other->hp -= damageRoll;
            out += to_string(damageRoll) + " damage. ";

            if (other->hp <= 0)
            {
                other->color = "red";
                other->alive = false;
            }
        }
        hit ? log->alert(out) : log->message(out);
    }

    int distanceTo(std::shared_ptr<Actor> other)
    {
        auto _x = pow(x - other->x, 2);
        auto _y = pow(y - other->y, 2);
        return static_cast<int>(sqrt(_x + _y));
    }

    bool inRange(std::shared_ptr<Actor> other)
    {
        return distanceTo(other) <= range;
    }

    std::string name;
    int ac = 10;
    int toHit = 0;
    dice dice = dice::d4;
    int hp = 10;
    int range = 1;
    bool alive = true;

    roller r;
};



