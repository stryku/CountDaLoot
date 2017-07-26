#pragma once

#include "loot/ILootStatsObserver.hpp"
#include "view/summary/SummaryMonstersUpdater.hpp"
#include "view/summary/SummaryItemsUpdater.hpp"

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            class SummaryUpdater : public loot::ILootStatsObserver
            {
            public:
                explicit SummaryUpdater(ui::controls::Table<2>& monstersTable, 
                                        ui::controls::Table<2>& lootTable);

                void notify(const std::unordered_map<std::string, size_t>& monsterKillCount,
                            const std::unordered_map<std::string, size_t>& lootStats) override;

            private:
                SummaryMonstersUpdater mMonsterUpdater;
                SummaryItemsUpdater mSummaryItemsUpdater;
            };
        }
    }
}
