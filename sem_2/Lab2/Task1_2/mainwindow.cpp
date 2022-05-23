#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "receipt.h"
#include "date.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
Receipt* recArr;
QString global_file_name;
int countRec;
int head;
int tail;
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
    if(s!="File_2L_Task1_2"){
        QMessageBox::information(this, "Ошибка!", "Неверный файл");
        file.close();
        return;
    }
    delete[] recArr;
    countRec=0;
    while (!file.eof()){
        string s1,s2,s3,s4;
        getline(file,s1);
        getline(file,s2);
        getline(file,s3);
        getline(file,s4);
        countRec++;
    }
    file.close();
    file.open(filePath);
    getline(file,s);
    recArr = new Receipt[countRec];
    head = 0;
    tail = countRec-1;

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Группа" << "Марка" << "Дата"<<"Состояние");
    for(int i=head;i!=-1;i=recArr[i].next){
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        string s1,s2,s3,s4;
        getline(file,s1);
        getline(file,s2);
        getline(file,s3);
        getline(file,s4);
        recArr[i].group=s1;
        recArr[i].mark=s2;
        recArr[i].date=s3;
        recArr[i].ready=s4;
        if(i!=0) recArr[i].previos = i-1;
        if(i!=countRec-1) recArr[i].next = i+1;
        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(s1));
        ui->tableWidget->setItem(i,0,itm1);
        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(s2));
        ui->tableWidget->setItem(i,1,itm2);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::fromStdString(s3));
        ui->tableWidget->setItem(i,2,itm3);
        QTableWidgetItem *itm4 = new QTableWidgetItem(QString::fromStdString(s4));
        ui->tableWidget->setItem(i,3,itm4);

    }
    file.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    int index = ui->spinBox->value();
    if(index == 0 || index > countRec) {
        QMessageBox::information(this, "Ошибка", "Участника под таким индексом нет");
        return;
    }
    index--;

    for(int i=head;i!=-1;i=recArr[i].next){
        if(index == 0) {
            if(i !=head) {
                recArr[recArr[i].previos].next = recArr[i].next;

            }
            else {
                head = recArr[head].next;
            }
            if(i != tail) {
                recArr[recArr[i].next].previos=recArr[i].previos;
            }
            else {
                tail=recArr[tail].previos;
            }
        }
        index--;

    }





    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Группа" << "Марка" << "Дата"<<"Состояние");

    int count =0;
    for(int i=head;i!=-1;i=recArr[i].next){
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        string s1,s2,s3,s4;
        s1=recArr[i].group;
        s2=recArr[i].mark;
        s3=recArr[i].date;
        s4=recArr[i].ready;
        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(s1));
        ui->tableWidget->setItem(count,0,itm1);
        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(s2));
        ui->tableWidget->setItem(count,1,itm2);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::fromStdString(s3));
        ui->tableWidget->setItem(count,2,itm3);
        QTableWidgetItem *itm4 = new QTableWidgetItem(QString::fromStdString(s4));
        ui->tableWidget->setItem(count,3,itm4);
        count++;

    }
    countRec--;


}


void MainWindow::on_pushButton_clicked()
{
    string s1,s2,s3,s4;
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
    if(s3.size()!=10) {
        QMessageBox::information(this, "Ошибка", "Неверная дата");
        return;
    }
    if(s3[2]!='.'||s3[5]!='.') {
        QMessageBox::information(this, "Ошибка", "Неверная дата");
        return;
    }
    for(int i=0;i<10;i++) {
        if(i==2 || i==5) continue;
        if((int)s3[i]<48 || (int)s3[i]>57){
            QMessageBox::information(this, "Ошибка", "Неверная дата");
            return;
        }

    }
    Date Check = s3;
    if(!Check.validCheck()) {
        QMessageBox::information(this, "Ошибка", "Неверная дата");
        return;
    }

    s4=ui->textEdit_4->toPlainText().toStdString();
    if(s4==""){
        QMessageBox::information(this, "Ошибка", "Не хватает данных");
        return;
    }
    if(s4!="Выполнен" && s4!="Не выполнен"){
        QMessageBox::information(this, "Ошибка", "Поле состояние: Выполнен/Не выполнен");
        return;
    }

    if(countRec==0) {
        delete[] recArr;
        countRec=1;
        recArr = new Receipt[countRec];
        head = 0;
        tail = countRec-1;
        recArr[0].group=s1;
        recArr[0].mark=s2;
        recArr[0].date=s3;
        recArr[0].ready=s4;
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Группа" << "Марка" << "Дата"<<"Состояние");
        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(s1));
        ui->tableWidget->setItem(0,0,itm1);
        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(s2));
        ui->tableWidget->setItem(0,1,itm2);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::fromStdString(s3));
        ui->tableWidget->setItem(0,2,itm3);
        QTableWidgetItem *itm4 = new QTableWidgetItem(QString::fromStdString(s4));
        ui->tableWidget->setItem(0,3,itm4);
        return ;
    }

    Receipt* temp = new Receipt[countRec+1];
    int count =0;
    for(int i=head;i!=-1;i=recArr[i].next){
        temp[count]=recArr[i];
        count++;

    }
    delete[] recArr;
    recArr=temp;
    countRec++;
    int i= countRec-1;
    recArr[i].group=s1;
    recArr[i].mark=s2;
    recArr[i].date=s3;
    recArr[i].ready=s4;
    tail = i;

    recArr[i].previos = i-1;
    recArr[recArr[i].previos].next=i;
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(s1));
    ui->tableWidget->setItem(i,0,itm1);
    QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(s2));
    ui->tableWidget->setItem(i,1,itm2);
    QTableWidgetItem *itm3 = new QTableWidgetItem(QString::fromStdString(s3));
    ui->tableWidget->setItem(i,2,itm3);
    QTableWidgetItem *itm4 = new QTableWidgetItem(QString::fromStdString(s4));
    ui->tableWidget->setItem(i,3,itm4);
}


void MainWindow::on_action_2_triggered()
{
    if(global_file_name==nullptr) {
        global_file_name = QFileDialog::getSaveFileName(this, "Выберите", ".", "*.txt");
        QMessageBox::information(this, "debug", global_file_name);
        QByteArray temp = global_file_name.toLocal8Bit();
        const char *filePath = temp.data();
        ofstream file_out(filePath);

        file_out<<"File_2L_Task1_2";
        if(countRec>0) {
            for(int i=head;i!=-1;i=recArr[i].next){
                file_out<<'\n'<<recArr[i].group<<'\n'<<recArr[i].mark<<'\n'<<recArr[i].date<<'\n'<<recArr[i].ready;

            }

        }
        return;
    }
    QByteArray temp = global_file_name.toLocal8Bit();
    const char *filePath = temp.data();
    ofstream file_out(filePath);
    file_out<<"File_2L_Task1_2";

    if(countRec>0) {
        for(int i=head;i!=-1;i=recArr[i].next){
            file_out<<'\n'<<recArr[i].group<<'\n'<<recArr[i].mark<<'\n'<<recArr[i].date<<'\n'<<recArr[i].ready;

        }

    }
}


void MainWindow::on_pushButton_3_clicked()
{
    int index = ui->spinBox_2->value();
    if(index == 0 || index > countRec) {
        QMessageBox::information(this, "Ошибка", "Участника под таким индексом нет");
        return;
    }
    index--;
    int i;

    for(i=head;index!=0;i=recArr[i].next){
        index--;
    }
    string s="Группа - "+recArr[i].group+'\n'+"Марка - "+recArr[i].mark+'\n'+"Дата - "+recArr[i].date+'\n'+"Состояние готовности - "+recArr[i].ready;
    QMessageBox::information(this, "Ошибка", QString::fromStdString(s));
}

void mQSort(int left, int right) {
    int f=left;
    int l=right;

    int x=f;
    int y=l;

    while(x != y){
        x=recArr[x].next;
        if(x==y) break;
        y=recArr[y].previos;
    }

    string middle = recArr[x].toSort();
    int current;
    bool flag;
    do {
        while(recArr[f].toSort()<middle) f=recArr[f].next;
        while(recArr[l].toSort()>middle) l=recArr[l].previos;
        flag=false;
        current = f;
        while(current!=-1){
            if(current==l) flag = true;
            current=recArr[current].next;
        }
        if(flag){

                string g;
                g=recArr[f].group;
                recArr[f].group=recArr[l].group;
                recArr[l].group=g;

                g=recArr[f].mark;
                recArr[f].mark=recArr[l].mark;
                recArr[l].mark=g;

                g=recArr[f].date;
                recArr[f].date=recArr[l].date;
                recArr[l].date=g;

                g=recArr[f].ready;
                recArr[f].ready=recArr[l].ready;
                recArr[l].ready=g;


                f=recArr[f].next;
                l=recArr[l].previos;


        }
        flag=false;
        if(f!=-1) {
            current = recArr[f].next;
            while(current!=-1){
                if(current==l) flag = true;
                current=recArr[current].next;
            }

        }

    } while(flag);

    flag=false;
    if(f!=-1){
        current = recArr[f].next;
        while(current!=-1){
            if(current==right) flag = true;
            current=recArr[current].next;
        }

    }
    if(flag)
        mQSort(f,right);

    flag=false;
    current = recArr[left].next;
    while(current!=-1){
        if(current==l) flag = true;
        current=recArr[current].next;
    }
    if(flag)
        mQSort(left,l);
}

void MainWindow::on_pushButton_4_clicked()
{
    mQSort(head, tail);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Группа" << "Марка" << "Дата"<<"Состояние");

    int count =0;
    for(int i=head;i!=-1;i=recArr[i].next){
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        string s1,s2,s3,s4;
        s1=recArr[i].group;
        s2=recArr[i].mark;
        s3=recArr[i].date;
        s4=recArr[i].ready;
        QTableWidgetItem *itm1 = new QTableWidgetItem(QString::fromStdString(s1));
        ui->tableWidget->setItem(count,0,itm1);
        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::fromStdString(s2));
        ui->tableWidget->setItem(count,1,itm2);
        QTableWidgetItem *itm3 = new QTableWidgetItem(QString::fromStdString(s3));
        ui->tableWidget->setItem(count,2,itm3);
        QTableWidgetItem *itm4 = new QTableWidgetItem(QString::fromStdString(s4));
        ui->tableWidget->setItem(count,3,itm4);
        count++;

    }
}

