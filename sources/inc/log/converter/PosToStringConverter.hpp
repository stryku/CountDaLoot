#pragma once

#include "structs/Pos.hpp"

#include <string>

namespace cdl
{
    namespace log
    {
        namespace convert
        {
            struct PosToStringConverter
            {
                template <typename PosField>
                static auto convert(const details::PosImpl<PosField>& pos)
                {
                    return "x: " + std::to_string(pos.x) +
                           " y: " + std::to_string(pos.y);
                }
            };
        }
    }
}
