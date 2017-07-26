#pragma once

#include "structs/Size.hpp"

#include <string>

namespace cdl
{
    namespace log
    {
        namespace convert
        {
            struct SizeToStringConverter
            {
                static auto convert(const Size& size)
                {
                    return " w: " + std::to_string(size.w) +
                           " h: " + std::to_string(size.h);
                }
            };
        }

    }
}
