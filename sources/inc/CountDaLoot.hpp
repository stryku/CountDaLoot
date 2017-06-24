#pragma once

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
        QApplication mApplication;
        MainWindow mWindow;
    };
}
