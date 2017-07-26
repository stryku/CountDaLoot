#pragma once

#include <string>

namespace cdl
{
    namespace loot
    {
        struct LootData
        {
            size_t amount{ static_cast<size_t>(1) };
            std::string item;
        };
    }
}
