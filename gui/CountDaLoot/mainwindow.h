#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <functional>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow& getUi();
    void setAddInterestingItemCallback(std::function<void(const std::string&)> cb);

private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionAlways_on_top_triggered();

    void on_actionAlways_on_top_toggled(bool arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_ItemsSettingsPushButtonAdd_clicked();

private:
    Ui::MainWindow *ui;
    std::function<void(const std::string&)> mAddInterestingItemCallback;
};

#endif // MAINWINDOW_H
