#include "view/LootListUpdater.hpp"

namespace cdl
{
    namespace view
    {
        LootListUpdater::LootListUpdater(QTextEdit& textEdit)
            : mTextEditUpdater{ textEdit }
        {}

        void LootListUpdater::notify(const std::vector<std::string>& lines)
        {
            std::lock_guard<std::mutex> lock(mMutex);

            for (const auto& line : lines)
                mTextEditUpdater.append(transformLoot(line));
        }

        QString LootListUpdater::transformLoot(const std::string& lootLine) const
        {
            auto qstr = QString::fromStdString(lootLine);

            for (const auto& item : mItems)
            {
                qstr.replace(QString::fromStdString(item), 
                             QString{ "<span style='color:red'> %1 </span>" }.arg(QString::fromStdString(item)));
            }

            return qstr;
        }

        void LootListUpdater::setInterestingItems(const std::vector<std::string>& items)
        {
            std::lock_guard<std::mutex> lock(mMutex);
            mItems = items;
        }
    }
}
