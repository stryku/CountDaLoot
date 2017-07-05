#pragma once

#include "graphics/Image.hpp"
#include "loot/tab/LootTabCoordinates.hpp"
#include "loot/tab/LootTabFinder.hpp"
#include "loot/tab/LootTabState.hpp"
#include "log/StructLogger.hpp"

namespace cdl
{
    namespace loot
    {
        namespace tab
        {
            struct LootTabData;

            class LootTabProvider
            {
            public:
                explicit LootTabProvider();
                LootTabData getTab();

            private:
                graphics::Image getScreen() const;
                bool tabHasMoved(const graphics::Image& screen) const;
                LootTabState getTabState(const graphics::Image& screen) const;

                const graphics::Image mLootActivePattern;
                const graphics::Image mLootInactivePattern;
                const graphics::Image mLootInactiveRedPattern;

                LootTabCoordinates mLastCoordinates;
                LootTabFinder mLootTabFinder;
                log::StructLogger mStructLogger;
            };
        }
    }
}
