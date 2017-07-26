#pragma once

#include "loot/ILootObserver.hpp"
#include "updater/TextEditUpdater.hpp"
#include "view/LootListViewType.hpp"

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
            void setViewType(LootListViewType type);

        private:
            QString transformLoot(const std::string& lootLine) const;
            std::vector<std::string> filterLines(const std::vector<std::string>& lines) const;
            void reshow();

            qt::TextEditUpdater mTextEditUpdater;
            std::vector<std::string> mItems;
            std::vector<std::string> mLootLines;
            std::mutex mMutex;
            LootListViewType mViewType{ LootListViewType::All };
        };
    }
}
