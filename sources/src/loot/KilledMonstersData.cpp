#include "loot/KilledMonstersData.hpp"

#include "loot/parse/LootLineParser.hpp"
#include "loot/parse/ParsedLootLine.hpp"

namespace cdl
{
    namespace loot
    {
        void KilledMonsterData::notify(const std::vector<std::string>& lines)
        {
            parse::LootLineParser parser;

            for (const auto& line : lines)
            {
                const auto parsed = parser.parse(line);

                ++mMonsterCount[parsed.monster];

                for (const auto& item : parsed.items)
                    mMonstersLoot[parsed.monster][item.item] += item.amount;
            }
        }
    }
}
