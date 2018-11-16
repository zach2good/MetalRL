#pragma once

#include "common.h"

struct Message
{
    Message(std::string text, std::string col = "white") : text(text), col(col) {}
    std::string text;
    std::string col;
};

class Log
{
public:
    void render() const
    {
        auto limit = (messages.size() > 7) ? 7 : messages.size();
        for (int i = 0; i < limit; ++i) {
            auto m = messages[(messages.size() - 1 - i)];
            auto col = color_from_name(m.col.data());
            auto alpha = col & (0x23000000 * i);
            terminal_color(col - alpha);
            terminal_print(15, 30 - 1 - i, m.text.data());
            //std::cout << m.text << std::endl;
        }
    }
    void message(std::string message) { messages.emplace_back(Message(message)); }
    void alert(std::string message) { messages.emplace_back(Message(message, "red")); }

private:
    std::vector<Message> messages;
};
