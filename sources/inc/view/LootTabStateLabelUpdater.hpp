#pragma once

#include "loot/tab/ILootTabStateObserver.hpp"

namespace cdl
{
    namespace view
    {
        class LootTabStateLabelUpdater : public loot::tab::ILootTabStateObserver
        {
        public:
            void notify(loot::tab::LootTabState state) override;
        };
    }
}
