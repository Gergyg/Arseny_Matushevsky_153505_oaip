#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hashtable.h"
#include <QMessageBox>
HashTable<int> hashTable;

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

void MainWindow::updateListWidget()
{
    ui->listWidget->clear();
    int countRow = hashTable.GetCapacity();
    std::stack<int> * arr = hashTable.GetArray();
    for(int i=0; i < countRow; i++) {
        QString res = "";
        std::stack<int> temp = arr[i];
        while(!temp.empty()){
            res+=QString::number(temp.top())+" ";
            temp.pop();
        }
        ui->listWidget->addItem(res);
    }
}




void MainWindow::on_pushButton_clicked()
{
    int value = ui->spinBox->value();
    hashTable.Add(value);
    updateListWidget();

}


void MainWindow::on_pushButton_2_clicked()
{
    int value = ui->spinBox_2->value();
    if(hashTable.Find(value) && hashTable.GetSize()>0){
        hashTable.Remove(value);
        QMessageBox::information(this, "Результат", "Элемент удален");
    } else {
        QMessageBox::information(this, "Результат", "Элемент не найден");
    }
    updateListWidget();
}


void MainWindow::on_pushButton_3_clicked()
{
    int value = ui->spinBox_3->value();
    if(hashTable.Find(value) && hashTable.GetSize()>0){
        QMessageBox::information(this, "Результат", "Элемент найден");
    } else {
        QMessageBox::information(this, "Результат", "Элемент не найден");
    }
}

int result = -1;
void MainWindow::on_pushButton_4_clicked()
{
    HashTable<int> taskTable;
    for(int i=0; i<50; i++){
        int r = rand()%100 + 1;
        taskTable.Add(r);
    }

    ui->listWidget_2->clear();
    int countRow = taskTable.GetCapacity();
    int mxvalue = -1, stackNumber = -1;
    std::stack<int> * arr = taskTable.GetArray();
    for(int i=0; i < countRow; i++) {
        QString res = "";
        std::stack<int> temp = arr[i];
        while(!temp.empty()){
            res+=QString::number(temp.top())+" ";
            if(temp.top()>mxvalue){
                stackNumber = i+1;
                mxvalue = temp.top();
            }
            temp.pop();
        }
        ui->listWidget_2->addItem(res);
    }

    result = stackNumber;

}



void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this,"Результат",QString::number(result)+"-й стек");
}

