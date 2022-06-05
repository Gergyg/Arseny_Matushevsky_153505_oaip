#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Set.h"
#include <QMessageBox>
using namespace stp;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Set<QString> a;
    a.insert("Hello world");
    if(a.find("Hello world")!=a.end())
        QMessageBox::information(this, "Результат", "rabotaet");
}

MainWindow::~MainWindow()
{
    delete ui;
}

