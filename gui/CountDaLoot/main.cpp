#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "graphics/Image.hpp"
#include "capture/ScreenCapturer.hpp"
#include "loot/tab/LootTabFinder.hpp"
#include "loot/tab/LootTabCoordinates.hpp"
#include "data/img/ImageDataProvider.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //auto pattern = cdl::graphics::Image::load("C:/moje/tmp/git/tlc/repo/tests/data/img/find/pattern_loot_active.bmp");
    //pattern.toCb();

    cdl::capture::ScreenCapturer capturer;
    
    auto screen = capturer.capture();
    screen.toCb();

    auto pattern = cdl::data::img::ImageDataProvider{}.getLootTabInactive();

    cdl::loot::tab::LootTabFinder finder;

    //auto pos = screen.findOneOf({ cdl::data::img::ImageDataProvider{}.getLootTabActive(), pattern });
    auto pos = finder.findCoordinates(screen);

    if (pos)
        //qDebug() << pos->x << " " << pos->y;
    qDebug() << pos->tabHeaderPos.x << " " << pos->tabHeaderPos.y;

    w.show();

    return a.exec();
}
