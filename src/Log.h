#pragma once

#include "common.h"

class Log
{
public:
    void render() const
    {
        int counter = 1;
        while (counter < messages.size())
        {
            terminal_color(color_from_argb(255/counter, 255, 255, 255));
            terminal_print(15, 30 - counter, messages[(messages.size() - counter)].data());
            counter++;
        }
    }
    std::vector<std::string> messages;
};

