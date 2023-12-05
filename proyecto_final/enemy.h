#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include "balas.h"


class Enemy: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:

    Enemy(QGraphicsItem * parent=0);
    QRectF boundingRect();
    void paint(QPainter *painter, QStyleOptionGraphicsItem *option, QWidget *widget);
    //int type() const;
 //   ~Enemy();

public slots:
    void move(); //movimiento de los enemigos
    void disparar();

private:
    QPixmap sprite;
    QTimer* timerB;
};

#endif // ENEMY_H
