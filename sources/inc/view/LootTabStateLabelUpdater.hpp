#pragma once

#include "loot/tab/ILootTabStateObserver.hpp"
#include "updater/LabelUpdater.hpp"

namespace cdl
{
    namespace view
    {
        class LootTabStateLabelUpdater : public loot::tab::ILootTabStateObserver
        {
        public:
            explicit LootTabStateLabelUpdater(QLabel& label);
            void notify(loot::tab::LootTabState state) override;

        private:
            qt::LabelUpdater mLabelUpdater;
            loot::tab::LootTabState mLastState{ loot::tab::LootTabState::NotVisible };
        };
    }
}
