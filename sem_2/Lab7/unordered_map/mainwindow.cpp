#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HashMap.h"
#include <QMessageBox>
HashMap<int,QString> hashmap;
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

void MainWindow::Update()
{
    ui->listWidget->clear();
    QString res;
    for(int i=0; i<hashmap.m; i++){
        res = "";
        node<int, QString> *ptr = hashmap.buckets[i];
        while (ptr != nullptr) {
            res += "map["; res+=QString::number(ptr->key); res+="]="; res+=ptr->value; res+=" ; ";
            ptr = ptr->next;
        }
        ui->listWidget->addItem(res);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int Key = ui->spinBox->value();
    QString Value = ui->textEdit->toPlainText();
    hashmap[Key] = Value;
    Update();
}


void MainWindow::on_pushButton_2_clicked()
{
    int Key = ui->spinBox_2->value();
    QString Value = ui->textEdit_2->toPlainText();
    hashmap.insert(Key, Value);
    Update();
}


void MainWindow::on_pushButton_3_clicked()
{
    int Key = ui->spinBox_3->value();
    hashmap.erase(Key);
    Update();
}


void MainWindow::on_pushButton_4_clicked()
{
    int Key = ui->spinBox_4->value();
    if(hashmap.contains(Key))
        QMessageBox::information(this, "Резальтат", "Содержится");
    else
        QMessageBox::information(this, "Резальтат", "Не содержится");
}


void MainWindow::on_pushButton_5_clicked()
{
    hashmap.clear();
    ui->listWidget->clear();
}

