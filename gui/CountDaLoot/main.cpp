#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "graphics/Image.hpp"
#include "text/TextReader.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto image = cdl::graphics::Image::load("C:/moje/tmp/git/tlc/repo/tests/data/loot_test.bmp");

    cdl::text::TextReader reader{ cdl::font::db::CharactersDb::load("C:/moje/tmp/git/tlc/repo/data/font_11.xml") };

    const auto text = reader.read(image);

    if (text)
        qDebug() << text->c_str();

    w.show();

    return a.exec();
}
