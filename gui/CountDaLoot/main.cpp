#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "graphics/Image.hpp"
#include "capture/ScreenCapturer.hpp"
#include "loot/tab/LootTabFinder.hpp"
#include "loot/tab/LootTabCoordinates.hpp"
#include "loot/tab/LootTabProvider.hpp"
#include "loot/tab/TabLootReader.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto tab = cdl::loot::LootTabProvider{}.getTab();
    while (!tab)
    {
        tab = cdl::loot::LootTabProvider{}.getTab();
    }


    tab->toCb();

    auto lines = cdl::loot::TabLootReader{}.read(*tab);

    for (auto line : lines)
        qDebug() << line.c_str();

    w.show();

    return a.exec();
}
