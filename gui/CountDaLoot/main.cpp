#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "graphics/Image.hpp"
#include "capture/ScreenCapturer.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto pattern = cdl::graphics::Image::load("C:/moje/tmp/git/tlc/repo/tests/data/img/find/pattern_loot_active.bmp");
    pattern.toCb();

    auto find_in = cdl::graphics::Image::load("C:/moje/tmp/git/tlc/repo/tests/data/img/find/tibia_screen.bmp");
    find_in.toCb();

    auto pos = find_in.find(pattern);

    if (pos)
        qDebug() << pos->x << " " << pos->y;

    w.show();

    return a.exec();
}
