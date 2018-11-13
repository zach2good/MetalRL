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

#if defined(__APPLE__)
#include <mach-o/dyld.h>
#include <sys/param.h>
#include <unistd.h>
#endif

#include "BearLibTerminal.h"
TERMINAL_TAKE_CARE_OF_WINMAIN

class Actor;

template<typename T> std::string to_string(const T& value)
{
    std::ostringstream ss;
    ss << value;
    return ss.str();
}