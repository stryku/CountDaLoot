#include "loot/tab/LootTabProvider.hpp"

#include "capture/ScreenCapturer.hpp"
#include "data/DataProvider.hpp"

namespace cdl
{
    namespace loot
    {
        LootTabProvider::LootTabProvider()
            : mLootActivePattern(data::DataProvider{}.getLootTabActive())
            , mLootInactivePattern(data::DataProvider{}.getLootTabInactive())
            , mLootInactiveRedPattern(data::DataProvider{}.getLootTabInactiveRed())
            , mLastCoordinates{ Offset{0,0}, Rect{} }
        {}

        bool LootTabProvider::tabHasMoved(const graphics::Image& screen) const
        {
            return !screen.isImageThere(Pos::from(mLastCoordinates.tabHeaderPos),
                                        mLootActivePattern);
        }

        boost::optional<graphics::Image> LootTabProvider::getTab()
        {
            const auto screen = getScreen();

            if (tabHasMoved(screen))
            {
                const auto newCoordinates = mLootTabFinder.findCoordinates(screen);

                if (!newCoordinates)
                    return{};

                mLastCoordinates = *newCoordinates;
            }

            return screen.getSprite(mLastCoordinates.tabArea);
        }

        graphics::Image LootTabProvider::getScreen() const
        {
            return capture::ScreenCapturer{}.capture();
        }
    }
}
