#pragma once

#include <string>

namespace cdl
{
    namespace font
    {
        class LootFont
        {
        public:
            static LootFont load(const std::string& path);
        };
    }
}
