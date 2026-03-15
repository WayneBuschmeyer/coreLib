#pragma once

#include "core/type_traits/remove_reference.h"

namespace core
{

    template<typename T>
    constexpr remove_reference_t<T>&& move(T&& value) noexcept
    {
        return static_cast<remove_reference_t<T>&&>(value);
    }

}