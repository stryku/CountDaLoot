#include "loot/parse/LootLineParser.hpp"

#include "loot/LootData.hpp"
#include "loot/parse/ParsedLootLine.hpp"

#include <boost/algorithm/string.hpp>

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
            std::string LootLineParser::removePreyInfo(const std::string& line) const
            {
                return line.substr(0, line.find_last_of('('));
            }

            ParsedLootLine LootLineParser::parse(std::string line) const
            {
                ParsedLootLine parsed;

                if (isWithPrey(line))
                {
                    parsed.withPrey = isWithPrey(line);
                    line = removePreyInfo(line);
                }

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
                LootData ld;

                if (isdigit(item[0]))
                {
                    std::istringstream{ item } >> ld.amount;
                    item = item.substr(item.find(' '));
                }

                ld.item = boost::algorithm::trim_copy(item);

                return ld;
            }

            std::vector<std::string> LootLineParser::getStrItems(const std::string& line) const
            {
                const auto semicolonPos = line.find(':');
                return split(line.substr(semicolonPos + 2), ',');
            }

            std::string LootLineParser::getMonsterName(std::string line) const
            {
                const auto kLootOfA = std::string{ "Loot of a " };
                const auto kLootOfAn = std::string{ "Loot of an " };

                if(boost::algorithm::istarts_with(line, kLootOfAn))
                    line = line.substr(std::size(kLootOfAn));
                else if(boost::algorithm::istarts_with(line, kLootOfA))
                    line = line.substr(std::size(kLootOfA));

                const auto semicolonPos = line.find(':');

                return line.substr(0, semicolonPos);
            }

            bool LootLineParser::isWithPrey(const std::string& line) const
            {
                return line.find_last_of(')') != std::string::npos;
            }
        }
    }
}
