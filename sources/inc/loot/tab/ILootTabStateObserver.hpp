#pragma once

#include "loot/tab/LootTabState.hpp"

namespace cdl
{
    namespace loot
    {
        namespace tab
        {
            class ILootTabStateObserver
            {
            public:
                virtual ~ILootTabStateObserver() {}

                virtual void notify(LootTabState state) = 0;
            };
        }
    }
}
