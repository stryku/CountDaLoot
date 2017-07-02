#include "view/summary/MonsterMapSorter.hpp"

#include <iterator>
#include <algorithm>

namespace cdl
{
    namespace view
    {
        namespace summary
        {
            std::vector<std::pair<std::string, size_t>> MonsterMapSorter::sort(const std::unordered_map<std::string, size_t>& monsterMap) const
            {
                std::vector<std::pair<std::string, size_t>> container;

                container.reserve(monsterMap.size());
                std::copy(std::cbegin(monsterMap), std::cend(monsterMap), std::back_inserter(container));

                const auto pred = [](const std::pair<std::string, size_t>& lhs,
                                     const std::pair<std::string, size_t>& rhs)
                {
                    return lhs.second > rhs.second;
                };

                std::sort(std::begin(container), std::end(container), pred);

                return container;
            }
        }
    }
}
