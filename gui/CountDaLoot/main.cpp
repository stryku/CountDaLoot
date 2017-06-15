#include "mainwindow.h"
#include <QApplication>

#include "graphics/Image.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto image = cdl::graphics::Image::load("C:/moje/tmp/git/tlc/repo/data/img/loot_active.bmp");


    w.show();

    return a.exec();
}
