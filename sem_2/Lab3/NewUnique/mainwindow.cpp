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
#include "elementlist.h"
//using namespace std;
ElementList* elementlist;
QString global_file_name;

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


void MainWindow::on_pushButton_clicked()
{
    global_file_name = QFileDialog::getOpenFileName(this, "Выберите", QDir::currentPath(), "*.txt");
    QMessageBox::information(this, "debug", global_file_name);
    QByteArray temp = global_file_name.toLocal8Bit();
    const char *filePath = temp.data();
    std::ifstream file(filePath);
    delete elementlist;
    elementlist = new ElementList;
    char c;
    int stroka=1, stolbec=0;
    std::string s;
    while(getline(file,s)){
        for(int i=0;s[i];i++) {
            c=s[i];

            if(c=='\n') {
                stroka++;
                stolbec=0;
                continue;
            }
            stolbec++;

            if(c=='[' || c==']' || c=='{' || c=='}' || c=='(' || c==')'){
                elementlist->Push(new Element(c, stroka, stolbec));
                if( !elementlist->head->next && elementlist->head->is_opening==false){
                    std::string result="Строка - "+std::to_string(stroka)+", столбец - "+std::to_string(stolbec);
                    QString qresult=QString::fromStdString(result);
                    QMessageBox::information(this, "Неверно! (Закрывающая)", qresult);
                    return;
                }

                if(elementlist->head->is_opening==false) {
                    char close, open;
                    close=elementlist->head->skobka;
                    open=elementlist->head->next->skobka;
                    bool tr=true;
                    if(close == ']' && open != '[')
                        tr=false;
                    if(close == '}' && open != '{')
                        tr=false;
                    if(close == ')' && open != '(')
                        tr=false;
                    if(tr==false){
                        std::string result="Строка - "+std::to_string(stroka)+", столбец - "+std::to_string(stolbec);
                        QString qresult=QString::fromStdString(result);
                        QMessageBox::information(this, "Неверно! (Закрывающая)", qresult);
                        return;
                    }

                    elementlist->Pop();
                    elementlist->Pop();
                }
            }

        }

    stroka++;
    stolbec=0;
    }

    if(elementlist->head) {
        std::string result="Строка - "+std::to_string(elementlist->head->str)+", столбец - "+std::to_string(elementlist->head->stlb);
        QString qresult=QString::fromStdString(result);
        QMessageBox::information(this, "Неверно! (Открывающая)", qresult);
        return;
    }

    QMessageBox::information(this, "Information", "Success");
}


void MainWindow::on_pushButton_2_clicked()
{
    QString str=ui->textEdit->toPlainText();
    std::string s=str.toStdString();

    delete elementlist;
    elementlist = new ElementList;
    char c;
    int stroka=1, stolbec=0;
        for(int i=0;s[i];i++) {
            c=s[i];

            if(c=='\n') {
                stroka++;
                stolbec=0;
                continue;
            }
            stolbec++;

            if(c=='[' || c==']' || c=='{' || c=='}' || c=='(' || c==')'){
                elementlist->Push(new Element(c, stroka, stolbec));
                if( !elementlist->head->next && elementlist->head->is_opening==false){
                    std::string result="Строка - "+std::to_string(stroka)+", столбец - "+std::to_string(stolbec);
                    QString qresult=QString::fromStdString(result);
                    QMessageBox::information(this, "Неверно! (Закрывающая)", qresult);
                    return;
                }

                if(elementlist->head->is_opening==false) {
                    char close, open;
                    close=elementlist->head->skobka;
                    open=elementlist->head->next->skobka;
                    bool tr=true;
                    if(close == ']' && open != '[')
                        tr=false;
                    if(close == '}' && open != '{')
                        tr=false;
                    if(close == ')' && open != '(')
                        tr=false;
                    if(tr==false){
                        std::string result="Строка - "+std::to_string(stroka)+", столбец - "+std::to_string(stolbec);
                        QString qresult=QString::fromStdString(result);
                        QMessageBox::information(this, "Неверно! (Закрывающая)", qresult);
                        return;
                    }

                    elementlist->Pop();
                    elementlist->Pop();
                }
            }
        }







    if(elementlist->head) {
        std::string result="Строка - "+std::to_string(elementlist->head->str)+", столбец - "+std::to_string(elementlist->head->stlb);
        QString qresult=QString::fromStdString(result);
        QMessageBox::information(this, "Неверно! (Открывающая)", qresult);
        return;
    }

    QMessageBox::information(this, "Information", "Success");
}
