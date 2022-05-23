#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPolygonItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(0,0,1400,600,this);
    ui->graphicsView->setScene(scene);
    scene->addLine(0,381,1400,381,QPen(QBrush(Qt::black),3));


    animationTimer = new QTimer(this);
    connect(animationTimer, SIGNAL(timeout()), this, SLOT(onTranslate()));


}

MainWindow::~MainWindow()
{
    delete ui;
}


/*mainRect::mainRect(): QGraphicsRectItem(0)
{
    QColor color = QColor(2,2,2);
    setBrush(color);
    setRect(0,0,200,60);
    setPos(10,10);

    new firstTriangle(QPointF(0,0),this);
    new secondTriangle(QPointF(0,0),this);
    new firstChassi(QPointF(0,0),this);
    new secondChassi(QPointF(0,0),this);
}*/

mainRect::mainRect()
{

}

QRectF mainRect::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(400,100));

}

void mainRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(0,0,200,60);

}
void MainWindow::onTranslate()
{
    if(item->x()<700){




            if(item->y()>300) {

                item->moveBy(xspeed,0);
                item2->moveBy(xspeed,0);
                item3->moveBy(xspeed,0);
                item4->moveBy(xspeed,0);
                item5->moveBy(xspeed,0);

            }

            else {

                item->moveBy(xspeed, 50.0/y());
                item2->moveBy(xspeed, 50.0/y());
                item3->moveBy(xspeed, 50.0/y());
                item4->moveBy(xspeed, 50.0/y());
                item5->moveBy(xspeed, 50.0/y());

            }



    }

    else {
        if(item->x()<1100) {
            item->moveBy(100000.0/(x()*x()),0);
            item2->moveBy(100000.0/(x()*x()),0);
            item3->moveBy(100000.0/(x()*x()),0);
            item4->moveBy(100000.0/(x()*x()),0);
            item5->moveBy(100000.0/(x()*x()),0);
        }

    }
    if((item2->rotation()>-89.9)){
        item2->setRotation(item2->rotation()-0.1);
    }
    if(item3->rotation()>-89.9){
        item3->setRotation(item3->rotation()-0.1);
    }

}
/*void mainRect::advance(int phase)
{
    if(x()<700){


        if(phase){

            if(y()>300) {

                moveBy(xspeed,0);

            }

            else {

                moveBy(xspeed, 50.0/y());

            }


        }
    }

    else {
        if(x()<1100) {
            moveBy(100000.0/(x()*x()),0);
        }

    }
}

firstTriangle::firstTriangle(QPointF initPos, QGraphicsItem *parent) : QGraphicsPolygonItem(parent)
{
    QPolygon polygon;
    setBrush(Qt::red);
    setPen(QPen(QBrush(Qt::red),1));

    polygon<<QPoint(0,0)<<QPoint(0,-40)<<QPoint(60,0);
    setPolygon(polygon);
    setPos(initPos);

}

secondTriangle::secondTriangle(QPointF initPos, QGraphicsItem *parent) : QGraphicsPolygonItem(parent)
{

    QPolygon polygon;
    setBrush(Qt::green);
    setPen(QPen(QBrush(Qt::green),1));

    polygon<<QPoint(200,0)<<QPoint(270,60)<<QPoint(200,60);
    setPolygon(polygon);
    setPos(initPos);
}

firstChassi::firstChassi(QPointF initPos, QGraphicsItem *parent) : QGraphicsLineItem(parent)
{

    setPen(QPen(QBrush(Qt::black),3));
    setLine(50,59,29,59);
    setPos(initPos);
    this->setTransformOriginPoint(50,59);

}

void firstChassi::advance(int phase)
{

    if(phase&&(rotation()>-89.9)){
        this->setRotation(rotation()-0.1);
    }

}

secondChassi::secondChassi(QPointF initPos, QGraphicsItem *parent) : QGraphicsLineItem(parent)
{
    setPen(QPen(QBrush(Qt::black),3));
    setLine(150,59,129,59);
    setPos(initPos);
    this->setTransformOriginPoint(150,59);


}
*/
secondChassi::secondChassi()
{

}

QRectF secondChassi::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(500,500));

}

void secondChassi::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawLine(150,59,129,59);

}

/*void secondChassi::advance(int phase)
{
    if(phase&&(rotation()>-89.9)){
        this->setRotation(rotation()-0.1);
    }
}*/

void MainWindow::on_pushButton_clicked()
{

    //scene->removeItem(item);
    //animationTimer->stop();
    item = new mainRect();
    scene->addItem(item);
    item2= new secondChassi;
    item2->setTransformOriginPoint(150,59);
    scene->addItem(item2);
    item3= new firstChassi;
    item3->setTransformOriginPoint(50,59);
    scene->addItem(item3);
    item4= new firstTriangle;
    scene->addItem(item4);
    item5=new secondTriangle;
    scene->addItem(item5);
    animationTimer->start(1000/200);
}


firstChassi::firstChassi()
{

}

QRectF firstChassi::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(500,500));

}

void firstChassi::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawLine(50,59,29,59);

}

firstTriangle::firstTriangle()
{

}

QRectF firstTriangle::boundingRect() const
{
    return QRectF(QPoint(-40,-40),
                  QPoint(500,500));

}

void firstTriangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygon polygon;
    painter->setBrush(Qt::green);
    painter->setPen(QPen(QBrush(Qt::green),1));

    polygon<<QPoint(200,0)<<QPoint(270,60)<<QPoint(200,60);
    painter->drawPolygon(polygon);

}

secondTriangle::secondTriangle()
{

}

QRectF secondTriangle::boundingRect() const
{

    return QRectF(QPoint(-40,-40),
                  QPoint(500,500));
}

void secondTriangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygon polygon;
    painter->setBrush(Qt::red);
    painter->setPen(QPen(QBrush(Qt::red),1));

    polygon<<QPoint(0,0)<<QPoint(0,-20)<<QPoint(40,0);
    painter->drawPolygon(polygon);

}
