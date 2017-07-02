#pragma once

#include "loot/ILootStatsObserver.hpp"
#include "view/summary/SummaryMonstersUpdater.hpp"

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            class SummaryUpdater : public loot::ILootStatsObserver
            {
            public:
                explicit SummaryUpdater(ui::controls::Table<2>& mTable);

                void notify(const std::unordered_map<std::string, size_t>& monsterKillCount,
                            const std::unordered_map<std::string, std::unordered_map<std::string, size_t>>& monstersLootStats) override;

            private:
                SummaryMonstersUpdater mMonsterUpdater;
            };
        }
    }
}
