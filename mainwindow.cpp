#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymodel.h"
#include "mydelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _model = new MyModel();
    _delegate = new MyDelegate(this);

    ui->listView->setModel(_model);
    ui->listView->setItemDelegate(_delegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
