#pragma once

#include <string>
#include <unordered_map>

namespace cdl
{
    namespace loot
    {
        class ILootStatsObserver
        {
        public:
            virtual ~ILootStatsObserver() {}

            virtual void notify(const std::unordered_map<std::string, size_t>& monsterKillCount,
                                const std::unordered_map<std::string, std::unordered_map<std::string, size_t>>& monstersLootStats) = 0;
        };
    }
}
