#pragma once

#include "structs/Rgba.hpp"

#include <string>

namespace cdl
{
    namespace log
    {
        namespace convert
        {
            struct RgbaToStringConverter
            {
                static auto convert(const Rgba& rgba)
                {
                    return "r: " + std::to_string(rgba.r) +
                           " g: " + std::to_string(rgba.g) +
                           " b: " + std::to_string(rgba.b) +
                           " a: " + std::to_string(rgba.a);
                }
            };
        }

    }
}
