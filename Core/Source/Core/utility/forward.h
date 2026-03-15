#pragma once

#include "core/type_traits/remove_reference.h"

namespace core
{

    template<typename T>
    constexpr T&& forward(remove_reference_t<T>& value) noexcept
    {
        return static_cast<T&&>(value);
    }

    template<typename T>
    constexpr T&& forward(remove_reference_t<T>&& value) noexcept
    {
        return static_cast<T&&>(value);
    }

}