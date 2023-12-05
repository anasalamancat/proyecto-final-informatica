#ifndef BALAS_H
#define BALAS_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QtMath>

enum tipoMovimiento {
    Parabolico,
    Circular
};


class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet( float _posx, float _posy, int _direcion, tipoMovimiento tipo, QGraphicsItem * parent=0);
    setPosicion(float _x, float _y);

public slots:
    void alternarMove();
    void move();
    void moveCircular();

private:
    tipoMovimiento tipoMovi; // Tipo de movimiento de la bala
    float velocidad = 15.0f; // La velocidad inicial de la bala, en unidades por segundo
    float anguloLanzamiento = 5.0f; // El ángulo de lanzamiento de la bala, en grados
    float gravedad = -9.8f; // La gravedad que afecta a la bala, en unidades por segundo al cuadrado
    float tiempoVuelo = 0.0f; // El tiempo de vuelo de la bala, en segundos
    float velocidadAngular = 0.09f; // La velocidad angular de la bala para el movimiento circular
    float radio = 90.0f; // El radio del movimiento circular
    float anguloC; // El ángulo actual de la bala en el movimiento circular
    float posX;
    float posY;
    float radioInicial;
    float alturaInicial;
    int direccion;

};
#endif // BALAS_H
