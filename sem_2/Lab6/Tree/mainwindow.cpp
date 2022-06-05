#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
AVLTree Tree;
using namespace std;
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

int taskResult = 0;
void MainWindow::update(){
    taskResult = 0;
    ui->treeWidget->clear();
    if(!Tree.root) return;
    QTreeWidgetItem* Root = new QTreeWidgetItem();
    Root->setText(0, QString::fromStdString(to_string(Tree.root->item.first)));
    Root->setText(1, QString::fromStdString(to_string(Tree.root->item.second)));
    ui->treeWidget->addTopLevelItem(Root);
    updateTreeWidget(Tree.root, Root);

}

void MainWindow::updateTreeWidget(Node* item, QTreeWidgetItem * parent) {
    if(item->left && item->right) taskResult++;
    if(item->left) {
        Node* left_item = item->left;
        QTreeWidgetItem* Left = new QTreeWidgetItem();
        Left->setText(0, QString::fromStdString(to_string(left_item->item.first)));
        Left->setText(1, QString::fromStdString(to_string(left_item->item.second)));
        parent->addChild(Left);
        updateTreeWidget(left_item, Left);
    }
    if(item->right) {
        Node* right_item = item->right;
        QTreeWidgetItem* Right = new QTreeWidgetItem();
        Right->setText(0, QString::fromStdString(to_string(right_item->item.first)));
        Right->setText(1, QString::fromStdString(to_string(right_item->item.second)));
        parent->addChild(Right);
        updateTreeWidget(right_item, Right);
    }
}



void MainWindow::on_pushButton_4_clicked()
{
    int Key = ui->spinBox->value();
    int Item = ui->spinBox_2->value();

    Tree.add(make_pair(Key, Item));

    update();
}


void MainWindow::on_pushButton_5_clicked()
{
    int Key = ui->spinBox_3->value();
    int Item = Tree.getEntry(Key);

    if(Item == -1){
        ui->textEdit_2->setText("Не найден");
    } else {
        ui->textEdit_2->setText("Результат: "+QString::number(Item));
    }

}


void MainWindow::on_pushButton_6_clicked()
{
    int Key = ui->spinBox_4->value();
    if(Tree.remove(Key)){
        QMessageBox::information(this, "Результат выполнения", "Удаление выполнено");
    } else {
        QMessageBox::information(this, "Результат выполнения", "Такого ключа нет");
    }
    update();
}

QString result="";

void output(int &a, int &b){
    result+=QString::number(a)+" - "+QString::number(b)+"\n";
}

void MainWindow::on_pushButton_clicked()
{
    result = "";
    Tree.preorderTraverse(output);
    ui->textEdit->setText(result);
}


void MainWindow::on_pushButton_3_clicked()
{
    result = "";
    Tree.postorderTraverse(output);
    ui->textEdit->setText(result);
}


void MainWindow::on_pushButton_2_clicked()
{
    result = "";
    Tree.inorderTraverse(output);
    ui->textEdit->setText(result);
}


void MainWindow::on_pushButton_7_clicked()
{
    QMessageBox::information(this, "Результат", QString::number(taskResult));
}

