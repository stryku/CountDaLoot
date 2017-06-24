#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "graphics/Image.hpp"
#include "capture/ScreenCapturer.hpp"
#include "loot/tab/LootTabFinder.hpp"
#include "loot/tab/LootTabCoordinates.hpp"
#include "loot/tab/LootTabProvider.hpp"
#include "loot/tab/TabLootReader.hpp"
#include "loot/NewLootProvider.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    cdl::loot::NewLootProvider provider;

    provider.start();

    w.show();

    return a.exec();
}
