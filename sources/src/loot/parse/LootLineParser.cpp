#include "loot/parse/LootLineParser.hpp"

#include "loot/LootData.hpp"
#include "loot/parse/ParsedLootLine.hpp"

#include <algorithm>
#include <sstream>
#include <iterator>

namespace
{
    template<typename Out>
    void split(const std::string &s, char delim, Out result) {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            *(result++) = item;
        }
    }


    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, std::back_inserter(elems));
        return elems;
    }
}

namespace cdl
{
    namespace loot
    {
        namespace parse
        {
            ParsedLootLine LootLineParser::parse(const std::string& line) const
            {
                ParsedLootLine parsed;

                parsed.monster = getMonsterName(line);
                const auto strItems = getStrItems(line);

                std::transform(std::cbegin(strItems), std::cend(strItems),
                               std::back_inserter(parsed.items),
                               [this](const std::string& item)
                               {
                                   return parseStrItem(item);
                               });

                return parsed;
            }

            LootData LootLineParser::parseStrItem(std::string item) const
            {
                if (item[0] == ' ')
                    item = item.substr(1);
                std::istringstream iss(item);
                LootData ld;

                if (isdigit(item[0]))
                    iss >> ld.amount;

                ld.item = iss.str();

                return ld;
            }


            std::vector<std::string> LootLineParser::getStrItems(const std::string& line) const
            {
                const auto semicolonPos = line.find(':');
                return split(line.substr(semicolonPos + 2), ',');
            }

            std::string LootLineParser::getMonsterName(std::string line) const
            {
                const auto kLootOf = std::string{ "Loot of a " };

                line = line.substr(std::size(kLootOf));

                const auto semicolonPos = line.find(':');

                return line.substr(0, semicolonPos);
            }
        }
    }
}
