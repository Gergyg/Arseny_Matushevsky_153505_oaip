#include "canvas.h"
#include "ui_canvas.h"
#include <QGraphicsSceneMouseEvent>
canvas::canvas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::canvas)
{
    ui->setupUi(this);
    paintscene = new paintScene();
    paintscene->setSceneRect(0, 0, 800, 600);
    ui->graphicsView->setScene(paintscene);
}

canvas::~canvas()
{
    delete ui;
}


paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse (event->scenePos().x() - 5,
                event->scenePos().y() - 5,
                10, 10,
                QPen(Qt::NoPen),
                QBrush(Qt::black));
    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::black, 10, Qt::SolidLine, Qt::RoundCap));
    previousPoint = event->scenePos();
}
