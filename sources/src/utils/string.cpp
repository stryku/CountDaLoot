#include "utils/string.hpp"

namespace cdl
{
    namespace utils
    {
        std::string removeSurroundingWhitespaces(std::string str)
        {
            const char* whitespaces{ " \t\n" };

            auto pos = str.find_first_not_of(whitespaces);

            if (pos == std::string::npos)
                return "";

            if (pos > 0)
                str = str.substr(pos);

            pos = str.find_last_not_of(whitespaces);

            if (pos != std::string::npos && pos < str.size() - 1)
                str.resize(pos + 1);

            return str;
        }
    }
}
