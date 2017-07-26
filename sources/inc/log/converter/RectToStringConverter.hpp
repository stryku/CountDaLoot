#pragma once

#include "structs/Rect.hpp"

#include <string>

namespace cdl
{
    namespace log
    {
        namespace convert
        {
            struct RectToStringConverter
            {
                static auto convert(const Rect& rect)
                {
                    return "x: " + std::to_string(rect.x) +
                           " y: " + std::to_string(rect.y) +
                           " w: " + std::to_string(rect.w) +
                           " h: " + std::to_string(rect.h);
                }
            };
        }

    }
}
