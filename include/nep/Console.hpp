#pragma once
#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <format>

namespace nep::con
{
    constexpr auto clear()
    {
        return "\x1b[2J";
    }

    constexpr auto cursorTo(int x, int y)
    {
        return std::format("\x1b[{};{}H", y, x);
    }

    constexpr auto cursorUp(int units)
    {
        return std::format("\x1b[{}A", units);
    }

    constexpr auto cursorLeft(int units)
    {
        return std::format("\x1b[{}D", units);
    }

    constexpr auto cursorDown(int units)
    {
        return std::format("\x1b[{}B", units);
    }

    constexpr auto cursorRight(int units)
    {
        return std::format("\x1b[{}C", units);
    }

    constexpr auto Black_Dim = "\x1b[30;0m";
    constexpr auto Red_Dim = "\x1b[31;0m";
    constexpr auto Green_Dim = "\x1b[32;0m";
    constexpr auto Yellow_Dim = "\x1b[33;0m";
    constexpr auto Blue_Dim = "\x1b[34;0m";
    constexpr auto Magenta_Dim = "\x1b[35;0m";
    constexpr auto Cyan_Dim = "\x1b[36;0m";
    constexpr auto White_Dim = "\x1b[37;0m";
    constexpr auto Black_Bright = "\x1b[30;1m";
    constexpr auto Red_Bright = "\x1b[31;1m";
    constexpr auto Green_Bright = "\x1b[32;1m";
    constexpr auto Yellow_Bright = "\x1b[33;1m";
    constexpr auto Blue_Bright = "\x1b[34;1m";
    constexpr auto Magenta_Bright = "\x1b[35;1m";
    constexpr auto Cyan_Bright = "\x1b[36;1m";
    constexpr auto White_Bright = "\x1b[37;1m";
    constexpr auto Reset = "\x1b[39;0m";
}


#endif