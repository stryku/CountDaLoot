#pragma once

#include <vector>

namespace cdl
{
    namespace loot
    {
        struct LootData;

        class ILootObserver
        {
        public:
            virtual ~ILootObserver() {}

            virtual void notify(const std::vector<LootData>& loots) = 0;
        };
    }
}
