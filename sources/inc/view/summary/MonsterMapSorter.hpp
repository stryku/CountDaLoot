#pragma once

#include <unordered_map>
#include <string>
#include <vector>

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            class MonsterMapSorter
            {
            public:
                std::vector<std::pair<std::string, size_t>> sort(const std::unordered_map<std::string, size_t>& monsterMap) const;
            };
        }
    }
}
