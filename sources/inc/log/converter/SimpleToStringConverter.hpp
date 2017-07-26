#pragma once

#include "utils/string.hpp"

namespace cdl
{
    namespace log
    {
        namespace converter
        {
            struct SimpleToStringConverter
            {
                template <typename Type>
                static auto convert(const Type& type)
                {
                    return utils::string::toString(type);
                }
            };
        }
    }
}
