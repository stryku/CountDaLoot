#pragma once

#include "loot/LootData.hpp"

#include <string>
#include <vector>

namespace cdl
{
    namespace loot
    {
        namespace parse
        {
            struct ParsedLootLine
            {
                std::string monster;
                std::vector<LootData> items;
            };
        }
    }
}
