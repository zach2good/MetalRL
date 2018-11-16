#pragma once

#include "common.h"

struct Message
{
    Message(const char* text, const char* col = "white") : text(text), col(col) {}
    const char* text;
    const char* col;
};

class Log
{
public:
    void render() const
    {
        if (messages.empty()) return;
        auto limit = (messages.size() > 7) ? 7 : messages.size();
        for (int i = 0; i < limit; ++i) {
            auto m = messages[(messages.size() - 1 - i)];
            auto col = color_from_name(m.col);
            auto alpha = col & (0x23000000 * i);
            terminal_color(col - alpha);
            terminal_print(15, 30 - 1 - i, m.text);
        }
    }
    std::vector<Message> messages;
};
