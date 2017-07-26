#pragma once

#include <string>
#include <vector>

namespace cdl
{
    namespace loot
    {
        class LootFilter
        {
        public:
            std::vector<std::string> filter(const std::vector<std::string>& currentlyStoredLoot,
                                            const std::vector<std::string>& readLoot) const;
        };
    }
}
