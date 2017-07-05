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
                , mStructLogger{ "default", "log/log.log" }
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
                    mStructLogger.log("Tab has moved. Last: ", mLastCoordinates.tabHeaderPos);

                    const auto newCoordinates = mLootTabFinder.findCoordinates(screen);

                    if (!newCoordinates)
                    {
                        mStructLogger.log("tab not found");
                        return LootTabData{ {}, LootTabState::NotVisible };
                    }

                    mLastCoordinates = *newCoordinates;
                    mStructLogger.log("Tab found. new coordinates: ", mLastCoordinates.tabHeaderPos, "new area: ", mLastCoordinates.tabArea);
                }

                LootTabData ret;

                ret.state = getTabState(screen);
                ret.tab = screen.getSprite(mLastCoordinates.tabArea);

                mStructLogger.log("detected tab state: ", utils::string::toString((static_cast<int>(ret.state))));

                return ret;
            }

            graphics::Image LootTabProvider::getScreen() const
            {
                return capture::ScreenCapturer{}.capture();
            }
        }
    }
}
