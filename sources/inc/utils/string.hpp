#pragma once

#include "utils/traits.hpp"

#include <string>

namespace cdl
{
    namespace utils 
    {
        namespace string
        {
            template <typename T>
            typename std::enable_if_t<std::is_convertible<T, std::string>::value, std::string>
                toString(const T &value)
            {
                return{ value };
            }

            template <typename T>
            typename std::enable_if_t<traits::canCallStdToString<T>::value, std::string>
                toString(const T &value)
            {
                return std::to_string(value);
            }

            std::string toString(bool value);

            template <typename ...Args>
            auto toStringArray(const Args&... args)
            {
                return std::array<std::string, sizeof...(Args)> { toString(args)... };
            }
        }
    }
}
