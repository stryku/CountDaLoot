#pragma once

#include <string>
#include <vector>

namespace cdl
{
    namespace loot
    {
        struct LootData;

        namespace parse
        {
            struct ParsedLootLine;

            class LootLineParser
            {
            public:
                ParsedLootLine parse(const std::string& line) const;

            private:
                std::string getMonsterName(std::string line) const;
                std::vector<std::string> getStrItems(const std::string& line) const;
                LootData parseStrItem(std::string item) const;
            };
        }
    }
}
