#include "view/summary/SummaryMonstersUpdater.hpp"

#include "view/summary/MonsterMapSorter.hpp"

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            SummaryMonstersUpdater::SummaryMonstersUpdater(ui::controls::Table<2>& table)
                :mTable{ table }
            {}

            void SummaryMonstersUpdater::update(const std::unordered_map<std::string, size_t>& monsterMap)
            {
                const auto sorted = MonsterMapSorter{}.sort(monsterMap);

                mTable.clear();

                for (const auto& pair : sorted)
                {
                    const auto& name = pair.first;
                    const auto& killCount = pair.second;

                    mTable.add(name, killCount);
                }
            }
        }
    }
}
