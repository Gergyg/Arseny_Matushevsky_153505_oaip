#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "que.h"
#include <QMessageBox>
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

Que<QString> quee;
int global = 0;
void MainWindow::on_pushButton_clicked()
{
    QString push_string = ui->textEdit->toPlainText();
    if ( push_string == "" ) {
        QMessageBox::information(this, "Ошибка", "Строка не должна быть пустой");
        return;
    }

    quee.push(push_string);
    ui->listWidget->addItem( push_string );
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->listWidget->count()==0){
        return;
    }

    quee.pop();
    ui->listWidget->takeItem(0);
}


void MainWindow::on_pushButton_4_clicked()
{
    if(ui->listWidget->count()==0){
        return;
    }

    QString back_result = quee.back();
    QMessageBox::information(this, "Результат", back_result);
}




void MainWindow::on_pushButton_2_clicked()
{
    if(ui->listWidget->count()==0){
        return;
    }

    QString front_result = quee.front();
    QMessageBox::information(this, "Результат", front_result);
}


void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(this, "Результат", QString::number(quee.size()));
}


void MainWindow::on_pushButton_6_clicked()
{
    if(quee.empty()){
        QMessageBox::information(this, "Результат", "Очередь пуста");
    }
    else {
        QMessageBox::information(this, "Результат", "Очередь не пуста");
    }
}

