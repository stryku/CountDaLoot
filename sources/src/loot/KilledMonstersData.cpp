#include "loot/KilledMonstersData.hpp"

#include "loot/parse/LootLineParser.hpp"
#include "loot/parse/ParsedLootLine.hpp"
#include "loot/ILootStatsObserver.hpp"

namespace cdl
{
    namespace loot
    {
        void KilledMonsterData::notify(const std::vector<std::string>& lines)
        {
            updateStats(lines);
            mStatsObsergers.notify(mMonsterCount, mItemsStats);
        }

        void KilledMonsterData::registerStatsObserver(ILootStatsObserver& observer)
        {
            mStatsObsergers.registerObserver(observer);
        }

        void KilledMonsterData::updateStats(const std::vector<std::string>& lines)
        {
            parse::LootLineParser parser;

            for (const auto& line : lines)
            {
                const auto parsed = parser.parse(line);

                ++mMonsterCount[parsed.monster];

                for (const auto& item : parsed.items)
                {
                    mMonstersLoot[parsed.monster][item.item] += item.amount;
                    mItemsStats[item.item] += item.amount;
                }
            }
        }
    }
}
