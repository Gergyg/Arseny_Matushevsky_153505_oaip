#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "D:/Apps/qt/Lab4/stringlib/stringlib.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void findIfDeep();
    void coutOverloadedFunc();
    void findClass();
    void findChange();
    void findVar();
    void findError();


private slots:
    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
