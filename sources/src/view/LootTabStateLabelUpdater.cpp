#include "view/LootTabStateLabelUpdater.hpp"

#include <boost/assert.hpp>

namespace cdl
{
    namespace view
    {
        LootTabStateLabelUpdater::LootTabStateLabelUpdater(QLabel& label)
            : mLabelUpdater{ label }
        {}

        void LootTabStateLabelUpdater::notify(loot::tab::LootTabState state)
        {
            if (state == mLastState)
                return;

            mLastState = state;

            switch (state)
            {
                case loot::tab::LootTabState::Active:
                    mLabelUpdater.setText("Loot tab status: ACTIVE");
                    mLabelUpdater.setColor("green");
                    break;
                case loot::tab::LootTabState::Inactive:
                    mLabelUpdater.setText("Loot tab status: INACTIVE");
                    mLabelUpdater.setColor("orange");
                    break;
                case loot::tab::LootTabState::InactiveRed:
                    mLabelUpdater.setText("Loot tab status: INACTIVE RED");
                    mLabelUpdater.setColor("orange");
                    break;
                case loot::tab::LootTabState::NotVisible:
                    mLabelUpdater.setText("Loot tab status: NOT VISIBLE");
                    mLabelUpdater.setColor("red");
                    break;
                default:
                    BOOST_ASSERT_MSG(false, "Unexpected LootTabState value");
                    break;
            }
        }
    }
}
