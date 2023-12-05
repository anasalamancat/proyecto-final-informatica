#ifndef BALAS_H
#define BALAS_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QtMath>

class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet( float _posx, float _posy, int _direcion, QGraphicsItem * parent=0);
    setPosicion(float _x, float _y);

public slots:
    void move();

private:
    float velocidad = 10.0f; // La velocidad inicial de la bala, en unidades por segundo
    float anguloLanzamiento = 25.0f; // El ángulo de lanzamiento de la bala, en grados
    float gravedad = -9.8f; // La gravedad que afecta a la bala, en unidades por segundo al cuadrado
    float tiempoVuelo = 0.0f; // El tiempo de vuelo de la bala, en segundos
    float posX;
    float posY;
    int direccion;

};
#endif // BALAS_H
