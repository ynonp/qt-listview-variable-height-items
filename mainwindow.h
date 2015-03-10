#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MyModel;
class MyDelegate;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    MyModel *_model;
    MyDelegate *_delegate;
};

#endif // MAINWINDOW_H
