#include "view/summary/SummaryUpdater.hpp"

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            SummaryUpdater::SummaryUpdater(ui::controls::Table<2>& monstersTable,
                                           ui::controls::Table<2>& lootTable)
                : mMonsterUpdater{ monstersTable }
                , mSummaryItemsUpdater{ lootTable }
            {}

            void SummaryUpdater::notify(const std::unordered_map<std::string, size_t>& monsterKillCount,
                                        const std::unordered_map<std::string, size_t>& lootStats)
            {
                mMonsterUpdater.update(monsterKillCount);
                mSummaryItemsUpdater.update(lootStats);
            }
        }
    }
}
