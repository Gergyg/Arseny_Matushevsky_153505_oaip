#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QTableWidgetItem>
#include <string>
#include <fstream>
#include <QDebug>
#include <iostream>
#include "participantlist.h"
QString global_file_name;
using namespace std;
int countpart = 0;
ParticipantList* partlist = new ParticipantList;
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


void MainWindow::on_action_triggered()
{
    global_file_name = QFileDialog::getOpenFileName(this, "Выберите", QDir::currentPath(), "*.txt");
    QMessageBox::information(this, "debug", global_file_name);
    QByteArray temp = global_file_name.toLocal8Bit();
    const char *filePath = temp.data();
    ifstream file(filePath);
    string s;
    getline(file,s);
    if(s!="File_2L_Task1"){
        QMessageBox::information(this, "Ошибка!", "Неверный файл");
        file.close();
        return;
    }
    delete partlist;
    partlist = new ParticipantList;
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    countpart=0;

    while (!file.eof()){
        string s1,s2,s3;
        int i1,i2,i3,i4;
        getline(file,s1);
        getline(file,s2);
        getline(file,s3);

        getline(file,s);
        i1=atoi(s.c_str());
        getline(file,s);
        i2=atoi(s.c_str());
        getline(file,s);
        i3=atoi(s.c_str());
        getline(file,s);
        i4=atoi(s.c_str());
        //Participant* t =new Participant(s1,s2,s3,i1,i2,i3,i4);
        //my_shared_ptr<Participant> K = make_shared(*&t);
        partlist->Add(make_shared<Participant>(new Participant(s1,s2,s3,i1,i2,i3,i4)));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(s1));
        ui->tableWidget->setItem(countpart,0,itm1);
        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(s2));
        ui->tableWidget->setItem(countpart,1,itm2);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::fromStdString(s3));
        ui->tableWidget->setItem(countpart,2,itm3);
        QTableWidgetItem *itm4 = new QTableWidgetItem(QString::number(i1));
        ui->tableWidget->setItem(countpart,3,itm4);
        QTableWidgetItem *itm5 = new QTableWidgetItem(QString::number(i2));
        ui->tableWidget->setItem(countpart,4,itm5);
        QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(i3));
        ui->tableWidget->setItem(countpart,5,itm6);
        QTableWidgetItem *itm7 = new QTableWidgetItem(QString::number(i4));
        ui->tableWidget->setItem(countpart,6,itm7);
        countpart++;
    }
    file.close();
}

void MainWindow::on_pushButton_clicked()
{
    int index = ui->spinBox->value();
    if(index == 0 || index > countpart) {
        QMessageBox::information(this, "Ошибка", "Участника под таким индексом нет");
        return;
    }

    index--;
    partlist->Remove(index);


    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    countpart--;
    if(partlist->head) {
        my_shared_ptr<Participant> start = partlist->head;
    for(int i=0;i<countpart;i++) {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(start->country));
        ui->tableWidget->setItem(i,0,itm1);
        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(start->comandName));
        ui->tableWidget->setItem(i,1,itm2);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::fromStdString(start->fio));
        ui->tableWidget->setItem(i,2,itm3);
        QTableWidgetItem *itm4 = new QTableWidgetItem(QString::number(start->number));
        ui->tableWidget->setItem(i,3,itm4);
        QTableWidgetItem *itm5 = new QTableWidgetItem(QString::number(start->age));
        ui->tableWidget->setItem(i,4,itm5);
        QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(start->height));
        ui->tableWidget->setItem(i,5,itm6);
        QTableWidgetItem *itm7 = new QTableWidgetItem(QString::number(start->weight));
        ui->tableWidget->setItem(i,6,itm7);
        if(start->next) start=start->next;
        else break;

    }
    }
}

