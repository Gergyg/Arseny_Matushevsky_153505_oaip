#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

#include <QMouseEvent>
namespace Ui {
class canvas;
}

class paintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
private:
    QPointF previousPoint;



    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

class canvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = nullptr);
    ~canvas();

private:
    Ui::canvas *ui;
    paintScene *paintscene;
};


#endif // CANVAS_H
