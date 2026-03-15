#pragma once

#include <windows.h>

namespace core
{

inline unsigned long string_length(const char* text)
{
    unsigned long length{0};

    while (text[length] != '\0')
    {
        ++length;
    }

    return length;
}

inline void console_write(const char* text)
{
    HANDLE console{ GetStdHandle(STD_OUTPUT_HANDLE) };

    DWORD written{0};

    WriteConsoleA(
        console,
        text,
        string_length(text),
        &written,
        nullptr
    );
}

inline void console_write_char(char c)
{
    HANDLE console{ GetStdHandle(STD_OUTPUT_HANDLE) };

    DWORD written{0};

    WriteConsoleA(console, &c, 1, &written, nullptr);
}

}
