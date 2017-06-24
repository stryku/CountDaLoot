#pragma once

#include "loot/ILootObserver.hpp"
#include "updater/TextEditUpdater.hpp"

#include <mutex>

namespace cdl
{
    namespace view
    {
        class LootListUpdater : public loot::ILootObserver
                         
        {
        public:
            explicit LootListUpdater(QTextEdit& textEdit);

        public:
            void notify(const std::vector<std::string>& lines) override;
            void setInterestingItems(const std::vector<std::string>& items);

        private:
            QString transformLoot(const std::string& lootLine) const;

            qt::TextEditUpdater mTextEditUpdater;
            std::vector<std::string> mItems;
            std::mutex mMutex;
        };
    }
}
