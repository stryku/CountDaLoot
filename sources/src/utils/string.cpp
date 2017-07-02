#include "utils/string.hpp"

namespace cdl
{
    namespace utils
    {
        namespace string
        {
            std::string toString(bool value)
            {
                return value ? "true" : "false";
            }
        }
    }
}
