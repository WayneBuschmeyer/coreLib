#pragma once

#include "console.h"

namespace core
{

class ostream
{
public:

    ostream& operator<<(const char* text)
    {
        console_write(text);
        return *this;
    }

    ostream& operator<<(char c)
    {
        console_write_char(c);
        return *this;
    }

    ostream& operator<<(int value)
    {
        write_int(value);
        return *this;
    }

private:

    void write_int(int value)
    {
        if (value == 0)
        {
            console_write_char('0');
            return;
        }

        if (value < 0)
        {
            console_write_char('-');
            value = -value;
        }

        char buffer[32];
        int index{0};

        while (value > 0)
        {
            buffer[index++] = '0' + (value % 10);
            value /= 10;
        }

        while (index > 0)
        {
            --index;
            console_write_char(buffer[index]);
        }
    }

};

}
