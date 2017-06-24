#include "CountDaLoot.hpp"
#include "ui_mainwindow.h"

namespace cdl
{
    CountDaLoot::CountDaLoot(int argc, char* argv[])
        : mApplication{ argc, argv }
        , mLootListUpdater{ *mWindow.getUi().LootTextEdit }
    {
        mNewLootProvider.registerObserver(mLootListUpdater);

        mNewLootProvider.start();

        mWindow.setWindowTitle(QString("Count Da Loot %1").arg(CDL_VERSION));
    }

    int CountDaLoot::execute()
    {
        mWindow.show();
        return mApplication.exec();
    }
}
