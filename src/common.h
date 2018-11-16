#pragma once

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include <random>

#include <cmath>

#include "BearLibTerminal.h"

class Actor;

template<typename T> std::string to_string(const T& value)
{
    std::ostringstream ss;
    ss << value;
    return ss.str();
}

enum dice
{
    d4 = 4,
    d6 = 6,
    d8 = 8,
    d10 = 10,
    d12 = 12,
    d20 = 20,
    d100 = 100
};

struct roller
{
    int roll(dice d)
    {
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> roll(1, d);
        return roll(rng);
    }
};

class GameObject
{
public:
    GameObject(int x, int y, int ch, const char* color)
    : x(x), y(y), ch(ch), color(color) {}

    void render() const
    {
        terminal_color(color);
        terminal_put(x, y, ch);
    }

    virtual void step() = 0;

    int x;
    int y;
    int ch;
    const char* color;
};