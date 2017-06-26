#include "loot/tab/LootTabProvider.hpp"

#include "capture/ScreenCapturer.hpp"
#include "data/DataProvider.hpp"
#include "loot/tab/LootTabData.hpp"

namespace cdl
{
    namespace loot
    {
        namespace tab
        {
            LootTabProvider::LootTabProvider()
                : mLootActivePattern(data::DataProvider{}.getLootTabActive())
                , mLootInactivePattern(data::DataProvider{}.getLootTabInactive())
                , mLootInactiveRedPattern(data::DataProvider{}.getLootTabInactiveRed())
                , mLastCoordinates{ Offset{0,0}, Rect{} }
            {}

            LootTabState LootTabProvider::getTabState(const graphics::Image& screen) const
            {
                const auto headerPos = Pos::from(mLastCoordinates.tabHeaderPos);

                if (screen.isImageThere(headerPos, mLootActivePattern))
                    return LootTabState::Active;

                if (screen.isImageThere(headerPos, mLootInactivePattern))
                    return LootTabState::Inactive;

                if (screen.isImageThere(headerPos, mLootInactiveRedPattern))
                    return LootTabState::InactiveRed;

                return LootTabState::NotVisible;
            }


            bool LootTabProvider::tabHasMoved(const graphics::Image& screen) const
            {
                return !screen.isImageThere(Pos::from(mLastCoordinates.tabHeaderPos),
                                            mLootActivePattern);
            }

            LootTabData LootTabProvider::getTab()
            {
                const auto screen = getScreen();

                if (tabHasMoved(screen))
                {
                    const auto newCoordinates = mLootTabFinder.findCoordinates(screen);

                    if (!newCoordinates)
                        return LootTabData{ {}, LootTabState::NotVisible };

                    mLastCoordinates = *newCoordinates;
                }

                LootTabData ret;

                ret.state = getTabState(screen);
                ret.tab = screen.getSprite(mLastCoordinates.tabArea);

                return ret;
            }

            graphics::Image LootTabProvider::getScreen() const
            {
                return capture::ScreenCapturer{}.capture();
            }
        }
    }
}
