#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>

#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class mainRect : public QGraphicsObject {
public:
    mainRect();

    // QGraphicsItem interface
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
private:
    double xspeed = 0.5;

};



class firstTriangle : public mainRect{
public:
    firstTriangle();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

class secondTriangle: public mainRect{
public:
    secondTriangle();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

class firstChassi: public mainRect{
public:
    firstChassi();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;

};


class secondChassi: public mainRect{
public:
    secondChassi();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTranslate();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QGraphicsItem* view;
    QTimer* animationTimer;
    QTimer* generatorTimer;
    double xspeed = 0.5;

    mainRect *item = nullptr;
    secondChassi *item2 = nullptr;
    firstChassi *item3 = nullptr;
    firstTriangle *item4 = nullptr;
    secondTriangle *item5=nullptr;
};
#endif // MAINWINDOW_H
