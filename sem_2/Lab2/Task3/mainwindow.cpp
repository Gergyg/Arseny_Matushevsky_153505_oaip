#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
using namespace std;
#include "stack.h"
#include "queue.h"
#include <QMessageBox>
#include "finalstack.h"
Stack* mstack;
Queue* mqueue;
finalStack* mfinalstack;
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
    string s = ui->textEdit->toPlainText().toStdString();
    char c;
    for(int i=0;s[i];i++){
        if(s[i]!='a' && s[i]!='b' && s[i]!='c' && s[i]!='d' && s[i]!='e' && s[i]!='-' && s[i]!='+' && s[i]!='*' && s[i]!='/' && s[i]!='(' && s[i]!=')' && s[i]!='\n'){
            QMessageBox::information(this, "Ошибка!", "Неверное выражение");
            return;
        }
    }
    delete mstack;
    delete mqueue;
    mstack=new Stack;
    mqueue=new Queue;
    string result="";
    for(int i=0;s[i];i++){
        if(s[i]=='\n'){

            while(mstack->head){
                mqueue->Push(new Element(mstack->head->elem));
                mstack->Pop();
            }


            delete mfinalstack;
            mfinalstack = new finalStack;
            char p;
            double temp;
            double sec;
            while(mqueue->head) {
                result+=mqueue->head->elem;
                p=mqueue->head->elem;
                if(p=='a' || p=='b' || p=='c' || p=='d' || p=='e'){
                    switch(p){
                    case 'a':
                        temp=ui->doubleSpinBox->value();
                        break;
                    case 'b':
                        temp=ui->doubleSpinBox_2->value();
                        break;
                    case 'c':
                        temp=ui->doubleSpinBox_3->value();
                        break;
                    case 'd':
                        temp=ui->doubleSpinBox_4->value();
                        break;
                    default:
                        temp=ui->doubleSpinBox_5->value();
                        break;

                    }
                    mfinalstack->Push(new finalElement(temp));

                } else {
                    switch(p){
                    case '-':
                        sec=mfinalstack->head->elem;
                        mfinalstack->Pop();
                        mfinalstack->head->elem = mfinalstack->head->elem - sec;
                        break;
                    case '+':
                        sec=mfinalstack->head->elem;
                        mfinalstack->Pop();
                        mfinalstack->head->elem = mfinalstack->head->elem + sec;
                        break;
                    case '*':
                        sec=mfinalstack->head->elem;
                        mfinalstack->Pop();
                        mfinalstack->head->elem = mfinalstack->head->elem * sec;
                        break;
                    case '/':
                        sec=mfinalstack->head->elem;
                        if(sec == 0) {
                            QMessageBox::information(this, "Ошибка!", "Деление на ноль");
                            return;
                        }
                        mfinalstack->Pop();
                        mfinalstack->head->elem = mfinalstack->head->elem / sec;
                        break;
                    }
                }
                mqueue->Pop();

            }
            result+=" = ";
            result+=to_string(mfinalstack->head->elem);
            result+='\n';


            delete mstack;
            delete mqueue;
            mstack=new Stack;
            mqueue=new Queue;




        } else {   //if end

            c=s[i];
            if(c=='(') {
                mstack->Push(new Element(c));
                continue;
            }
            if(c==')') {
                while(mstack->head->elem!='('){
                    mqueue->Push(new Element(mstack->head->elem));
                    mstack->Pop();
                }
                mstack->Pop();
                continue;
            }

            if(c=='+' || c=='-' || c=='*' || c=='/') {
                if(!mstack->head){
                    mstack->Push(new Element(c));
                    continue;
                }
                if(mstack->head->elem=='('){
                    mstack->Push(new Element(c));
                    continue;
                }

                if( (c=='/' || c=='*') && (mstack->head->elem=='-' || mstack->head->elem=='+')) {
                    mstack->Push(new Element(c));
                    continue;
                }

                if(c=='/' || c=='*'){
                    while(mstack->head && mstack->head->elem != '+' && mstack->head->elem != '-' && mstack->head->elem != '(') {
                        mqueue->Push(new Element(mstack->head->elem));
                        mstack->Pop();
                    }
                    mstack->Push(new Element(c));
                    continue;
                }

                while(mstack->head && mstack->head->elem!='('){
                    mqueue->Push(new Element(mstack->head->elem));
                    mstack->Pop();
                }
                mstack->Push(new Element(c));
                continue;
            }
            mqueue->Push(new Element(c));


        } //else end


    } // for end
    if(mstack->head || mqueue->head){

        while(mstack->head){
            mqueue->Push(new Element(mstack->head->elem));
            mstack->Pop();
        }


        delete mfinalstack;
        mfinalstack = new finalStack;
        char p;
        double temp;
        double sec;
        while(mqueue->head) {
            result+=mqueue->head->elem;
            p=mqueue->head->elem;
            if(p=='a' || p=='b' || p=='c' || p=='d' || p=='e'){
                switch(p){
                case 'a':
                    temp=ui->doubleSpinBox->value();
                    break;
                case 'b':
                    temp=ui->doubleSpinBox_2->value();
                    break;
                case 'c':
                    temp=ui->doubleSpinBox_3->value();
                    break;
                case 'd':
                    temp=ui->doubleSpinBox_4->value();
                    break;
                default:
                    temp=ui->doubleSpinBox_5->value();
                    break;

                }
                mfinalstack->Push(new finalElement(temp));

            } else {
                switch(p){
                case '-':
                    sec=mfinalstack->head->elem;
                    mfinalstack->Pop();
                    mfinalstack->head->elem = mfinalstack->head->elem - sec;
                    break;
                case '+':
                    sec=mfinalstack->head->elem;
                    mfinalstack->Pop();
                    mfinalstack->head->elem = mfinalstack->head->elem + sec;
                    break;
                case '*':
                    sec=mfinalstack->head->elem;
                    mfinalstack->Pop();
                    mfinalstack->head->elem = mfinalstack->head->elem * sec;
                    break;
                case '/':
                    sec=mfinalstack->head->elem;
                    if(sec == 0) {
                        QMessageBox::information(this, "Ошибка!", "Деление на ноль");
                        return;
                    }
                    mfinalstack->Pop();
                    mfinalstack->head->elem = mfinalstack->head->elem / sec;
                    break;
                }
            }
            mqueue->Pop();

        }
        result+=" = ";
        result+=to_string(mfinalstack->head->elem);
        result+='\n';


        delete mstack;
        delete mqueue;
        mstack=new Stack;
        mqueue=new Queue;

    }
    ui->textEdit_2->setText(QString::fromStdString(result));

} // func end

