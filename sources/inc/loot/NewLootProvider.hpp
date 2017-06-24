#pragma once

#include <vector>

namespace cdl
{
    namespace loot
    {
        class ILootObserver;

        class NewLootProvider
        {
        public:
            void registerObserver(ILootObserver& observer);

        private:
            std::vector<ILootObserver&> mObservers;
        };
    }
}
