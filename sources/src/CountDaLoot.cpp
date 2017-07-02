#include "CountDaLoot.hpp"
#include "ui_mainwindow.h"

namespace cdl
{
    CountDaLoot::CountDaLoot(int argc, char* argv[])
        : mApplication{ argc, argv }
        , mLootListUpdater{ *mWindow.getUi().LootTextEdit }
        , mLootTabStateLabelUpdater{ *mWindow.getUi().labelLootTabStatus }
        , mInterestingItemsTable{ mWindow.getUi().ItemsSettingsTtableViewItems, {"Item"} }
        , mSummaryMonstersTable{ mWindow.getUi().SummaryTableViewMonsters, {"Monster", "Kill count" } }
        , mSummaryUpdater{ mSummaryMonstersTable }
    {
        mNewLootProvider.registerObserver(mLootListUpdater);
        mNewLootProvider.registerObserver(mKilledMonsterData);
        mNewLootProvider.registerTabStateObserver(mLootTabStateLabelUpdater);
        mKilledMonsterData.registerStatsObserver(mSummaryUpdater);

        mNewLootProvider.start();

        mWindow.setWindowTitle(QString("Count Da Loot %1").arg(CDL_VERSION));
        mWindow.setAddInterestingItemCallback(getAddInterestingItemCallback());
        mWindow.setLootListViewTypeChangedCallback(getLootListViewTypeChangedCallback());
    }

    int CountDaLoot::execute()
    {
        mWindow.show();
        return mApplication.exec();
    }

    std::function<void(const std::string&)> CountDaLoot::getAddInterestingItemCallback()
    {
        return [this](const std::string& item)
        {
            mInterestingItemsTable.add(item);
            mLootListUpdater.setInterestingItems(mInterestingItemsTable.getAll<std::string>());
        };
    }

    std::function<void(view::LootListViewType)> CountDaLoot::getLootListViewTypeChangedCallback()
    {
        return [this](view::LootListViewType type)
        {
            mLootListUpdater.setViewType(type);
        };
    }

}
