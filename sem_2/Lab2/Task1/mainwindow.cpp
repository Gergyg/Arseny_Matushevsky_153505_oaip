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
ParticipantList* partlist ;
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

        partlist->Add(new Participant(s1,s2,s3,i1,i2,i3,i4));
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


void MainWindow::on_pushButton_3_clicked()
{
    int index = ui->spinBox_5->value();
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
    if(partlist->head) {Participant* start = partlist->head;
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
        start=start->next;

    }
    }
}


void MainWindow::on_pushButton_clicked()
{
    string s1,s2,s3;
    int i1,i2,i3,i4;
    s1=ui->textEdit->toPlainText().toStdString();
    if(s1==""){
        QMessageBox::information(this, "Ошибка", "Не хватает данных");
        return;
    }
    s2=ui->textEdit_2->toPlainText().toStdString();
    if(s2==""){
        QMessageBox::information(this, "Ошибка", "Не хватает данных");
        return;
    }
    s3=ui->textEdit_3->toPlainText().toStdString();
    if(s3==""){
        QMessageBox::information(this, "Ошибка", "Не хватает данных");
        return;
    }

    i1=ui->spinBox->value();
    i2=ui->spinBox_2->value();
    i3=ui->spinBox_3->value();
    i4=ui->spinBox_4->value();


    if(countpart==0){
        partlist = new ParticipantList;
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(7);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    }
    partlist->Add(new Participant(s1,s2,s3,i1,i2,i3,i4));
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


void MainWindow::on_pushButton_2_clicked()
{
    string s = ui->textEdit_4->toPlainText().toStdString();
    string result="";
    if(!partlist->head) {
        QMessageBox::information(this, "Результат", "Нет результата");
        return;
    }
    Participant* start = partlist->head;
    for(int i=0;i<countpart;i++) {
        if(start->fio==s) {
            result+=start->country+"\n";
            result+=start->comandName+"\n";
            result+=start->fio+"\n";
            result+="Номер - "+to_string(start->number)+"\n";
            result+="Возраст - "+to_string(start->age)+"\n";
            result+="Рост - "+to_string(start->height)+"\n";
            result+="Вес - "+to_string(start->weight)+"\n";
            QMessageBox::information(this, "Результат", QString::fromStdString(result));
            return;
        }
        start=start->next;
    }
    QMessageBox::information(this, "Результат", "Нет результата");

}


void MainWindow::on_pushButton_4_clicked()
{
    int x=ui->spinBox_6->value();
    int y=ui->spinBox_7->value();
    string result="";
    if(y<x) {
        QMessageBox::information(this, "Результат", "Неверные от-до");
        return;
    }

    if(!partlist->head) {
        QMessageBox::information(this, "Результат", "Нет результата");
        return;
    }
    Participant* start = partlist->head;
    for(int i=0;i<countpart;i++) {
        if(start->weight>=x && start->weight<=y) {
            result+=start->comandName+" : ";
            result+=start->fio+"\n";
        }
        start=start->next;
    }
    if(result=="")
        QMessageBox::information(this, "Результат", "Нет результата");
    else
        QMessageBox::information(this, "Результат", QString::fromStdString(result));
}


void MainWindow::on_pushButton_5_clicked()
{
    int x=ui->spinBox_8->value();
    string result="";
    if(!partlist->head) {
        QMessageBox::information(this, "Результат", "Нет результата");
        return;
    }
    Participant* start = partlist->head;
    for(int i=0;i<countpart;i++) {
        if(start->height>=x) {
            result+=start->comandName+" : ";
            result+=start->fio+"\n";
        }
        start=start->next;
    }
    if(result=="")
        QMessageBox::information(this, "Результат", "Нет результата");
    else
        QMessageBox::information(this, "Результат", QString::fromStdString(result));
}


void MainWindow::on_pushButton_10_clicked()
{
    partlist->QSort_country(partlist->head,partlist->tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    if(partlist->head) {
        Participant* start = partlist->head;
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
            start=start->next;

        }

    } else {
        QMessageBox::information(this, "Результат", "Список не найден");
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    partlist->QSort_fio(partlist->head,partlist->tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    if(partlist->head) {
        Participant* start = partlist->head;
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
            start=start->next;

        }

    } else {
        QMessageBox::information(this, "Результат", "Список не найден");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    partlist->QSort_comandName(partlist->head,partlist->tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    if(partlist->head) {
        Participant* start = partlist->head;
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
            start=start->next;

        }

    } else {
        QMessageBox::information(this, "Результат", "Список не найден");
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    partlist->QSort_number(partlist->head,partlist->tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    if(partlist->head) {
        Participant* start = partlist->head;
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
            start=start->next;

        }

    } else {
        QMessageBox::information(this, "Результат", "Список не найден");
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    partlist->QSort_age(partlist->head,partlist->tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    if(partlist->head) {
        Participant* start = partlist->head;
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
            start=start->next;

        }

    } else {
        QMessageBox::information(this, "Результат", "Список не найден");
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    partlist->QSort_weight(partlist->head,partlist->tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    if(partlist->head) {
        Participant* start = partlist->head;
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
            start=start->next;

        }

    } else {
        QMessageBox::information(this, "Результат", "Список не найден");
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    partlist->QSort_height(partlist->head,partlist->tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Страна" << "Команда" << "ФИО"<<"Номер"<<"Возраст"<<"Рост"<<"Вес");
    if(partlist->head) {
        Participant* start = partlist->head;
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
            start=start->next;

        }

    } else {
        QMessageBox::information(this, "Результат", "Список не найден");
    }
}


void MainWindow::on_action_2_triggered()
{
    if(global_file_name==nullptr) {
        global_file_name = QFileDialog::getSaveFileName(this, "Выберите", ".", "*.txt");
        QMessageBox::information(this, "debug", global_file_name);
        QByteArray temp = global_file_name.toLocal8Bit();
        const char *filePath = temp.data();
        ofstream file_out(filePath);

        file_out<<"File_2L_Task1";
        if(partlist->head) {
            Participant* start = partlist->head;
            for(int i=0;i<countpart;i++) {
                file_out<<"\n"<<start->country<<"\n"<<start->comandName<<"\n"<<start->fio<<"\n"<<start->number<<"\n"<<start->age<<"\n"<<start->height<<"\n"<<start->weight;
                start=start->next;
            }

        }
        return;
    }
    QByteArray temp = global_file_name.toLocal8Bit();
    const char *filePath = temp.data();
    ofstream file_out(filePath);
    file_out<<"File_2L_Task1";

    if(partlist->head) {
        Participant* start = partlist->head;
        for(int i=0;i<countpart;i++) {
            file_out<<"\n"<<start->country<<"\n"<<start->comandName<<"\n"<<start->fio<<"\n"<<start->number<<"\n"<<start->age<<"\n"<<start->height<<"\n"<<start->weight;
            start=start->next;
        }

    }
}

