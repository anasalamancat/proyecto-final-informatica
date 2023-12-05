#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QObject>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "balasenemigos.h"

class enemigo: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    enemigo(QString direccion, int velocidadDisparos);
    ~enemigo();

    int getEnemy_direction_x() const;

    int getPosX() const;

    int getPosY() const;

public slots:
    void move(); //movimiento de los enemigos
    void disparar();

signals:
    void agregarBala(bool);

private:
    int enemy_direction_x;
    int ENEMY_SPEED_X;
    QGraphicsPixmapItem *sprite;
    QTimer* timerB;
    QTimer* timerMove;
    int posX;
    int posY;
};

#endif // ENEMIGO_H
