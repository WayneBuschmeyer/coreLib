#pragma once

#include "core/utility/move.h"

namespace core
{

    template<typename T>
    constexpr void swap(T& a, T& b) noexcept
    {
        T temp = move(a);
        a = move(b);
        b = move(temp);
    }

    template<typename T, unsigned long N>
    constexpr void swap(T(&a)[N], T(&b)[N]) noexcept
    {
        for (unsigned long i = 0; i < N; ++i)
            swap(a[i], b[i]);
    }

}