#pragma once

#include "loot/ILootObserver.hpp"
#include "updater/TextEditUpdater.hpp"

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

        private:
            qt::TextEditUpdater mTextEditUpdater;
        };
    }
}
