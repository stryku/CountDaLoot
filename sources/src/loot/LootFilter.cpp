#include "loot/LootFilter.hpp"

namespace cdl
{
    namespace loot
    {
        std::vector<std::string> LootFilter::filter(const std::vector<std::string>& currentlyStoredLoot,
                                                    const std::vector<std::string>& readLoot) const
        {
            auto currentIt = std::cbegin(currentlyStoredLoot);
            auto readIt = std::cbegin(readLoot);

            if (currentlyStoredLoot.size() > readLoot.size())
                currentIt = std::next(std::cend(currentlyStoredLoot), 
                                      -static_cast<int>(readLoot.size()));

            for (; 
                 currentIt != std::cend(currentlyStoredLoot); 
                 std::advance(currentIt, 1))
            {
                if (std::equal(currentIt, std::cend(currentlyStoredLoot),
                               readIt))
                {
                    const auto sameLootLinesCount = std::distance(currentIt, std::cend(currentlyStoredLoot));
                    std::advance(readIt, sameLootLinesCount);
                    break;
                }
            }

            return { readIt, std::cend(readLoot) };
        }
    }
}
