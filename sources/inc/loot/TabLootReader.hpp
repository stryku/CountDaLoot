#pragma once

namespace cdl
{
    namespace loot
    {
        class ILootObserver;

        class TabLootReader
        {
        public:
            void registerObserver(ILootObserver& observer) {}
        };
    }
}
