#pragma once

#include "graphics/Image.hpp"
#include "loot/tab/LootTabCoordinates.hpp"
#include "loot/tab/LootTabFinder.hpp"

#include <boost/optional.hpp>

namespace cdl
{
    namespace loot
    {
        class LootTabProvider
        {
        public:
            explicit LootTabProvider();
            boost::optional<graphics::Image> getTab();

        private:
            graphics::Image getScreen() const;
            bool tabHasMoved(const graphics::Image& screen) const;

            const graphics::Image mLootActivePattern;
            const graphics::Image mLootInactivePattern;
            const graphics::Image mLootInactiveRedPattern;

            loot::tab::LootTabCoordinates mLastCoordinates;
            loot::tab::LootTabFinder mLootTabFinder;
        };
    }
}
