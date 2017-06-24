#include "view/LootListUpdater.hpp"

#include <algorithm>

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

            const auto filtered = filterLines(lines);

            for (const auto& line : filtered)
                mTextEditUpdater.append(transformLoot(line));

            mLootLines.insert(std::end(mLootLines),
                              std::cbegin(lines), std::cend(lines));
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

            reshow();
        }

        void LootListUpdater::reshow()
        {
            const auto filtered = filterLines(mLootLines);

            mTextEditUpdater.clearDirectly();

            for (const auto& line : filtered)
                mTextEditUpdater.append(transformLoot(line));
        }


        void LootListUpdater::setViewType(LootListViewType type)
        {
            std::lock_guard<std::mutex> lock(mMutex);

            mViewType = type;

            reshow();
        }

        std::vector<std::string> LootListUpdater::filterLines(const std::vector<std::string>& lines) const
        {
            if (mViewType == LootListViewType::All)
                return lines;

            std::vector<std::string> filtered;

            std::copy_if(std::cbegin(lines),
                         std::cend(lines),
                         std::back_inserter(filtered),
                         [this](const auto& line)
                         {
                             for (const auto& item : mItems)
                                 if (line.find(item) != std::string::npos)
                                     return true;

                             return false;
                         });

            return filtered;
        }
    }
}
