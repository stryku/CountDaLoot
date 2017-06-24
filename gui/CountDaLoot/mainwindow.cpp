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

Ui::MainWindow& MainWindow::getUi()
{
    return *ui;
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
    const auto flags = windowFlags() | Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
    show();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}

void MainWindow::on_ItemsSettingsPushButtonAdd_clicked()
{
    if (mAddInterestingItemCallback)
        mAddInterestingItemCallback(ui->ItemsSettingsLineEditItemName->text().toStdString());
}

void MainWindow::setAddInterestingItemCallback(std::function<void(const std::string&)> cb)
{
    mAddInterestingItemCallback = cb;
}
