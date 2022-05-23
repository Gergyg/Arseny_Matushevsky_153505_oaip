#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Quelist.h"
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
    unique_ptr<Quelist<int>> listt(new Quelist<int>());
    srand(time(NULL));
    QString result="";
    int mx = 0;
    int mn = 200;
    int imx = 0;
    int imn = 0;
    for(int i=0; i<10; i++){
        int r = rand()%100+1;
        result+=QString::number(r);
        result+=" ";
        listt->Add(r);

        if(r > mx){
            mx = r;
            imx = i;
        }
        if(r < mn){
            mn = r;
            imn = i;
        }
    }
    if(imx < imn) {
        swap(imx,imn);
    }
    ui->textEdit_1->setText(result);

    result="";
    unique_ptr<Quelist<int>> listt2(new Quelist<int>());
    for(int i=0; i<5; i++){
        int r = rand()%100+1;
        result+=QString::number(r);
        result+=" ";
        listt2->Add(r);
    }
    ui->textEdit_2->setText(result);
    QString ans = "";
    unique_ptr<Quelist<int>> templist(new Quelist<int>());
    shared_ptr<Node<int>> temp = listt->head;
    for(int i=0; i<= imn; i++){
        templist->Add(temp->data);
        ans+=QString::number(temp->data);
        ans+=" ";
        if(i<imn) temp = temp->next;
    }
    shared_ptr<Node<int>> temp2 = listt2->head;
    for(int i=0; i<5; i++){
        templist->Add(temp2->data);
        ans+=QString::number(temp2->data);
        ans+=" ";
        if(temp2->next) temp2 = temp2->next;
    }

    for(int i=imn+1; i<=imx; i++){
        temp = temp->next;
    }

    for(int i=imx; i< 10; i++){
        templist->Add(temp->data);
        ans+=QString::number(temp->data);
        ans+=" ";
        if(i<9) temp = temp->next;
    }

    ui->textEdit_3->setText(ans);
    ui->textEdit_4->setText(result);
}

