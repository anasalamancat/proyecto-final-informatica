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

    enemigo(QString direccion, int _velocidadDisparos);
    ~enemigo();
    int getEnemy_direction_x() const;
    int getPosX() const;
    int getPosY() const;
    void pararDisparos();

public slots:
    void move();
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
    int velocidadDisparos;
};

#endif // ENEMIGO_H
