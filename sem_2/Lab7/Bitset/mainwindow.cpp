#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Bitset.h"
Bitset<20> bitset;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem(QString::fromStdString(bitset.to_string()));
    ui->listWidget->addItem(QString::number(bitset.to_ullong()));
    ui->listWidget->addItem(QString::number(bitset.to_ulong()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_7_clicked()
{
    size_t value = ui->spinBox_3->value();
    bitset.flip(value);
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(bitset.to_string()));
    ui->listWidget->addItem(QString::number(bitset.to_ullong()));
    ui->listWidget->addItem(QString::number(bitset.to_ulong()));
}


void MainWindow::on_pushButton_6_clicked()
{
    size_t value = ui->spinBox_3->value();
    bitset.reset(value);
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(bitset.to_string()));
    ui->listWidget->addItem(QString::number(bitset.to_ullong()));
    ui->listWidget->addItem(QString::number(bitset.to_ulong()));
}


void MainWindow::on_pushButton_5_clicked()
{
    size_t value = ui->spinBox_3->value();
    bitset.set(value);
    ui->listWidget->clear();
    ui->listWidget->addItem(QString::fromStdString(bitset.to_string()));
    ui->listWidget->addItem(QString::number(bitset.to_ullong()));
    ui->listWidget->addItem(QString::number(bitset.to_ulong()));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit_2->clear();
    size_t value = ui->spinBox_3->value();
    if(bitset.test(value))
        ui->textEdit_2->setText("test : true");
    else
        ui->textEdit_2->setText("test : false");

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_2->clear();
    if(bitset.any())
        ui->textEdit_2->setText("any : true");
    else
        ui->textEdit_2->setText("any : false");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->textEdit_2->clear();
    if(bitset.all())
        ui->textEdit_2->setText("all : true");
    else
        ui->textEdit_2->setText("all : false");
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->textEdit_2->clear();
    if(bitset.none())
        ui->textEdit_2->setText("none : true");
    else
        ui->textEdit_2->setText("none : false");
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->textEdit_2->clear();
    ui->textEdit_2->setText("count : "+QString::number(bitset.count()));
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->textEdit_2->clear();
    ui->textEdit_2->setText("Size : "+QString::number(bitset.Size()));
}

