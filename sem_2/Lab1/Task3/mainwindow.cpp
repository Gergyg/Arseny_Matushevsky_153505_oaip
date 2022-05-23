#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QTableWidgetItem>
#include <fstream>
#include <iostream>
#include <date.h>
#include "secondwindow.h"
#include <QDebug>
std::string globDate;
QString global_file_name;
int count_dates;
using namespace std;
Date *dates;
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

void MainWindow::on_action_4_triggered() //сохранить
{

    /*for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        if (ui->tableWidget->item(i, 0)->text().toStdString() =="" ){
            continue;
        }
        std::string s=ui->tableWidget->item(i,0)->text().toStdString();
        if(s.size()!=10) {
            QMessageBox::information(this, "error", "неверные данные");
            return;
        }
        if(s[2]!='.'||s[5]!='.') {
            QMessageBox::information(this, "error", "неверные данные");
            return;
        }
        for(int i=0;i<10;i++) {
            if(i==2 || i==5) continue;
            if((int)s[i]<48 || (int)s[i]>57){
                QMessageBox::information(this, "error", "неверные данные");
                return;
            }

        }
        Date Check = s;
        if(!Check.validCheck()) {
            QMessageBox::information(this, "error", "неверные данные");
            return;
        }
    }*/
    QByteArray temp = global_file_name.toLocal8Bit();
    const char *filePath = temp.data();
    ofstream file_out(filePath);
    file_out<<"00.00.0000 ";

    for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        if (ui->tableWidget->item(i, 0)->text().toStdString() ==""){
            continue;
        }
        file_out << ui->tableWidget->item(i, 0)->text().toStdString() << ' ';
    }
    file_out.close();
}


void MainWindow::on_action_3_triggered() //открыть
{
    global_file_name = QFileDialog::getOpenFileName(this, "Выберите", QDir::currentPath(), "*.txt");
    QMessageBox::information(this, "debug", global_file_name);
    QByteArray temp = global_file_name.toLocal8Bit();
    const char *filePath = temp.data();
    ifstream file(filePath);
    string s;
    file>>s;
    if(s!="00.00.0000"){
        QMessageBox::information(this, "error", "неверный файл");
        file.close();
        return;
    }
    vector < string > newData;
    while (file >> s){
        newData.push_back(s);
    }
    file.close();
    delete dates;
    count_dates=0;
    dates = new Date[newData.size()];
    for (int i = 0; i < int(newData.size()); i++){
        dates[i] = newData[i];
        count_dates++;
    }
    ui->tableWidget->setRowCount(newData.size());
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Дата" << "Следующий День" << "Разница");
    for (int i = 0; i < ui->tableWidget->rowCount(); i++){

        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(dates[i].formatDate));
        ui->tableWidget->setItem(i, 0, itm1);

        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(dates[i].NextDay().formatDate));
        ui->tableWidget->setItem(i, 1, itm2);

        if(i != 0) {
            std::cout<<dates[i].Duration(dates[i-1]);
            QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(dates[i].Duration(dates[i-1])));
            ui->tableWidget->setItem(i-1, 2, itm3);
        } else {
            QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(dates[0].Duration(dates[count_dates-1])));
            ui->tableWidget->setItem(count_dates-1, 2, itm3);
        }

    }
}

bool isNum(char x){
    if (x < '0' || x > '9'){
        return 0;
    }
    return 1;
}

void MainWindow::on_pushButton_2_clicked()
{
    QTableWidgetItem *itm = ui->tableWidget->currentItem();
    if (itm == 0){
        QMessageBox::information(this, "error", "не указана ячейка");
        return;
    }
    string curDate = itm->text().toStdString();
    if (curDate[2] != '.' || curDate[5] != '.' || curDate.size() != 10){
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    if (!isNum(curDate[0]) || !isNum(curDate[1]) || !isNum(curDate[3]) || !isNum(curDate[4]) || !isNum(curDate[6]) || !isNum(curDate[7]) || !isNum(curDate[8]) || !isNum(curDate[9])){
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    Date birthDay = curDate;
    if (!birthDay.validCheck()){
        QMessageBox::information(this, "error", "неверный формат");
        return;
    }
    globDate = curDate;
    SecondWindow window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    QTableWidgetItem *itm = ui->tableWidget->currentItem();
    if (itm == 0){
        QMessageBox::information(this, "error", "не указана ячейка");
        return;
    }
    string curDate = itm->text().toStdString();
    if (curDate[2] != '.' || curDate[5] != '.' || curDate.size() != 10){
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    if (!isNum(curDate[0]) || !isNum(curDate[1]) || !isNum(curDate[3]) || !isNum(curDate[4]) || !isNum(curDate[6]) || !isNum(curDate[7]) || !isNum(curDate[8]) || !isNum(curDate[9])){
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    Date birthDay = curDate;
    if (!birthDay.validCheck()){
        QMessageBox::information(this, "error", "неверный формат");
        return;
    }

    QMessageBox::information(this, "Номер недели", tr("%1").arg(birthDay.WeekNumber()));
}


void MainWindow::on_pushButton_clicked()
{
    QTableWidgetItem *itm = ui->tableWidget->currentItem();
    if (itm == 0){
        QMessageBox::information(this, "error", "не указана ячейка");
        return;
    }
    string curDate = itm->text().toStdString();
    if (curDate[2] != '.' || curDate[5] != '.' || curDate.size() != 10){
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    if (!isNum(curDate[0]) || !isNum(curDate[1]) || !isNum(curDate[3]) || !isNum(curDate[4]) || !isNum(curDate[6]) || !isNum(curDate[7]) || !isNum(curDate[8]) || !isNum(curDate[9])){
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    Date birthDay = curDate;
    if (!birthDay.validCheck()){
        QMessageBox::information(this, "error", "неверный формат");
        return;
    }

    QMessageBox::information(this, "Предыдущий день", QString::fromStdString(birthDay.PreviousDay().formatDate));
}


void MainWindow::on_pushButton_4_clicked()
{
    if(global_file_name==nullptr) {
        QMessageBox::information(this, "error", "Файл не выбран");
        return;
    }
    std::string s=ui->textEdit->toPlainText().toStdString();
    if(s.size()!=10) {
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    if(s[2]!='.'||s[5]!='.') {
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    for(int i=0;i<10;i++) {
        if(i==2 || i==5) continue;
        if((int)s[i]<48 || (int)s[i]>57){
            QMessageBox::information(this, "error", "неверные данные");
            return;
        }

    }
    Date Check = s;
    if(!Check.validCheck()) {
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }

    count_dates++;
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    Date *temp = new Date[count_dates];
    for(int i=0;i<count_dates-1;i++){
        temp[i]=dates[i];
    }
    temp[count_dates-1] = Check;
    delete[] dates;
    dates = temp;

    QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(dates[count_dates-1].formatDate));
    ui->tableWidget->setItem(count_dates-1, 0, itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(dates[count_dates-1].NextDay().formatDate));
    ui->tableWidget->setItem(count_dates-1, 1, itm2);

    QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(dates[count_dates-1].Duration(dates[count_dates-2])));
    ui->tableWidget->setItem(count_dates-2, 2, itm3);

    QTableWidgetItem *itm4 = new QTableWidgetItem(QString::number(dates[count_dates-1].Duration(dates[0])));
    ui->tableWidget->setItem(count_dates-1, 2, itm4);

    QFile file(global_file_name);
    file.open(QFile::ReadWrite);
    QTextStream outstream(&file);
    QString t=QString::fromStdString(s);

    //qint64 fileSize = file.size();
    //qDebug() << fileSize;
    //outstream.seek(fileSize);
    outstream.seek(11*(count_dates));
    outstream << t << ' ';

    file.close();
}


void MainWindow::on_pushButton_5_clicked()
{
    if(global_file_name==nullptr) {
        QMessageBox::information(this, "error", "Файл не выбран");
        return;
    }
    if(ui->spinBox->value()>count_dates || ui->spinBox->value()<1) {
        QMessageBox::information(this, "error", "Даты под таким номером нет");
        return;
    }
    int id = ui->spinBox->value();
    std::string s=ui->textEdit_2->toPlainText().toStdString();
    if(s.size()!=10) {
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    if(s[2]!='.'||s[5]!='.') {
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    for(int i=0;i<10;i++) {
        if(i==2 || i==5) continue;
        if((int)s[i]<48 || (int)s[i]>57){
            QMessageBox::information(this, "error", "неверные данные");
            return;
        }

    }
    Date Check = s;
    if(!Check.validCheck()) {
        QMessageBox::information(this, "error", "неверные данные");
        return;
    }
    dates[id-1]=s;
    QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(dates[id-1].formatDate));
    ui->tableWidget->setItem(id-1, 0, itm1);

    QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(dates[id-1].NextDay().formatDate));
    ui->tableWidget->setItem(id-1, 1, itm2);

    if(id-1 != 0) {
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(dates[id-1].Duration(dates[id-1-1])));
        ui->tableWidget->setItem(id-1-1, 2, itm3);
        if(id!=count_dates){
            QTableWidgetItem *itm5 = new QTableWidgetItem(QString::number(dates[id-1].Duration(dates[id])));
            ui->tableWidget->setItem(id-1, 2, itm5);
        } else {
            QTableWidgetItem *itm6 = new QTableWidgetItem(QString::number(dates[id-1].Duration(dates[0])));
            ui->tableWidget->setItem(id-1, 2, itm6);
        }
    } else {
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(dates[0].Duration(dates[count_dates-1])));
        ui->tableWidget->setItem(count_dates-1, 2, itm3);
        if(count_dates>1){
            QTableWidgetItem *itm4 = new QTableWidgetItem(QString::number(dates[0].Duration(dates[1])));
            ui->tableWidget->setItem(0, 2, itm4);

        }
    }


    QFile file(global_file_name);
    file.open(QFile::ReadWrite);
    QTextStream outstream(&file);
    QString t=QString::fromStdString(s);

    //qint64 fileSize = file.size();
    //qDebug() << fileSize;
    //outstream.seek(fileSize);
    outstream.seek(11*(id));
    outstream << t << ' ';

    file.close();
}


void MainWindow::on_pushButton_6_clicked()
{
    if(global_file_name==nullptr) {
        QMessageBox::information(this, "error", "Файл не выбран");
        return;
    }
    if(ui->spinBox->value()>count_dates || ui->spinBox->value()<1) {
        QMessageBox::information(this, "error", "Даты под таким номером нет");
        return;
    }
    int id = ui->spinBox_2->value()-1;

    int pos=0;
    Date *temp = new Date[count_dates-1];
    for(int i=0;i<count_dates;i++){
        if(i==id) continue;

        temp[pos]=dates[i];
        pos++;
    }
    count_dates--;
    //temp[count_dates-1] = Check;
    delete[] dates;
    dates = temp;
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(count_dates);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Дата" << "Следующий День" << "Разница");
    for (int i = 0; i < ui->tableWidget->rowCount(); i++){

        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(dates[i].formatDate));
        ui->tableWidget->setItem(i, 0, itm1);

        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(dates[i].NextDay().formatDate));
        ui->tableWidget->setItem(i, 1, itm2);

        if(i != 0) {
            std::cout<<dates[i].Duration(dates[i-1]);
            QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(dates[i].Duration(dates[i-1])));
            ui->tableWidget->setItem(i-1, 2, itm3);
        } else {
            QTableWidgetItem *itm3 = new QTableWidgetItem(QString::number(dates[0].Duration(dates[count_dates-1])));
            ui->tableWidget->setItem(count_dates-1, 2, itm3);
        }

    }
    QByteArray tempo = global_file_name.toLocal8Bit();
    const char *filePath = tempo.data();
    ofstream file_out(filePath);
    file_out<<"00.00.0000 ";

    for (int i = 0; i < ui->tableWidget->rowCount(); i++){
        if (ui->tableWidget->item(i, 0)->text().toStdString() ==""){
            continue;
        }
        file_out << ui->tableWidget->item(i, 0)->text().toStdString() << ' ';
    }
    file_out.close();

}

