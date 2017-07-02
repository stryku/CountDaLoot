#include "view/summary/SummaryUpdater.hpp"

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            SummaryUpdater::SummaryUpdater(ui::controls::Table<2>& table)
                : mMonsterUpdater{ table }
            {}

            void SummaryUpdater::notify(const std::unordered_map<std::string, size_t>& monsterKillCount,
                                        const std::unordered_map<std::string, std::unordered_map<std::string, size_t>>& monstersLootStats)
            {
                mMonsterUpdater.update(monsterKillCount);
            }
        }
    }
}
