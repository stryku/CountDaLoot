#pragma once

#include "view/LootListUpdater.hpp"
#include "view/LootTabStateLabelUpdater.hpp"
#include "loot/NewLootProvider.hpp"
#include "ui/controls/Table.hpp"

#include "mainwindow.h"
#include <QApplication>
#include <QDebug>


namespace cdl
{
    class CountDaLoot
    {
    public:
        explicit CountDaLoot(int argc, char* argv[]);
        int execute();

    private:
        std::function<void(const std::string&)> getAddInterestingItemCallback();
        std::function<void(view::LootListViewType)> getLootListViewTypeChangedCallback();

        QApplication mApplication;
        MainWindow mWindow;
        view::LootListUpdater mLootListUpdater;
        view::LootTabStateLabelUpdater mLootTabStateLabelUpdater;
        loot::NewLootProvider mNewLootProvider;
        ui::controls::Table<1> mInterestingItemsTable;
    };
}
