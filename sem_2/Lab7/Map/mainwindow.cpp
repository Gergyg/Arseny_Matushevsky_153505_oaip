#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
Map<int, int> mp;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    int cnt = 0;
    for(auto &item:mp){
        std::cout<<cnt++;
        ui->tableWidget->insertRow ( ui->tableWidget->rowCount() );
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                 0,
                                 new QTableWidgetItem(QString::number(item.first)));
        ui->tableWidget->setItem   ( ui->tableWidget->rowCount()-1,
                                 1,
                                 new QTableWidgetItem(QString::number(item.second)));
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    int key = ui->spinBox_2->value();
    int value = ui->spinBox_5->value();
    mp.insert(std::make_pair(key,value));
    update();
}


void MainWindow::on_pushButton_3_clicked()
{
    int key = ui->spinBox_3->value();
    mp.erase(key);
    update();
}


void MainWindow::on_pushButton_5_clicked()
{
    mp.clear();
    ui->tableWidget->clear();
}

