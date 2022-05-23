#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Deque.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Deque<int> q;
    q.push_back(5);
    q.push_front(2);
    q.push_back(3);
    for(int i=0; i<100; i++){
        q.push_back(i);
    }
    QMessageBox::information(this, "KEK", QString::number(q[102]));
}

Deque<QString> dque;
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString push_string = ui->textEdit->toPlainText();
    if ( push_string == "" ) {
        QMessageBox::information(this, "Ошибка", "Строка не должна быть пустой");
        return;
    }

    dque.push_front(push_string);
    ui->listWidget->insertItem(0, push_string );
}


void MainWindow::on_pushButton_2_clicked()
{
    QString push_string = ui->textEdit_2->toPlainText();
    if ( push_string == "" ) {
        QMessageBox::information(this, "Ошибка", "Строка не должна быть пустой");
        return;
    }

    dque.push_back(push_string);
    ui->listWidget->addItem( push_string );
}


void MainWindow::on_pushButton_4_clicked()
{
    if(ui->listWidget->count()==0){
        return;
    }

    dque.pop_front();
    ui->listWidget->takeItem(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->listWidget->count()==0){
        return;
    }

    dque.pop_back();
    ui->listWidget->takeItem(ui->listWidget->count()-1);
}


void MainWindow::on_pushButton_5_clicked()
{
    dque.clear();
    ui->listWidget->clear();
}


void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::information(this, "Результат", QString::number(dque.size()));
}


void MainWindow::on_pushButton_7_clicked()
{
    if(dque.empty()){
        QMessageBox::information(this, "Результат", "Очередь пуста");
    }
    else {
        QMessageBox::information(this, "Результат", "Очередь не пуста");
    }
}

