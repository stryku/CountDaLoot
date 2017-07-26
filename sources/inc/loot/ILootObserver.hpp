#pragma once

#include <string>
#include <vector>

namespace cdl
{
    namespace loot
    {
        class ILootObserver
        {
        public:
            virtual ~ILootObserver() {}

            virtual void notify(const std::vector<std::string>& loots) = 0;
        };
    }
}
