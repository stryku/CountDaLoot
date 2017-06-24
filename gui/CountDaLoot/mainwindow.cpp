#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{

}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSave_as_triggered()
{

}

void MainWindow::on_actionAlways_on_top_triggered()
{

}

void MainWindow::on_actionAlways_on_top_toggled(bool arg1)
{

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}
