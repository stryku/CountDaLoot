#pragma once

#include "loot/ILootObserver.hpp"
#include "utils/ObserversContainer.hpp"

#include <unordered_map>

namespace cdl
{
    namespace loot
    {
        class ILootStatsObserver;

        class KilledMonsterData : public ILootObserver
        {
        public:
            void notify(const std::vector<std::string>& lines) override;
            void registerStatsObserver(ILootStatsObserver& observer);

        private:
            void updateStats(const std::vector<std::string>& lines);

            std::unordered_map<std::string, size_t> mMonsterCount;
            std::unordered_map<std::string, std::unordered_map<std::string, size_t>> mMonstersLoot;
            utils::ObserversContainer<ILootStatsObserver> mStatsObsergers;
        };
    }
}
