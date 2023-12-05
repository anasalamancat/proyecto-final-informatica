#ifndef BALASENEMIGOS_H
#define BALASENEMIGOS_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QtMath>

class balasenemigos: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    balasenemigos( float _posx, float _posy, int _direcion, QString direccion);
    ~balasenemigos();
    setPosicion(float _x, float _y);

public slots:
    void move();

private:
    QTimer *timerBalas;
    QGraphicsPixmapItem *imagenBala;
    float velocidad = 10.0f; // La velocidad inicial de la bala, en unidades por segundo
    float anguloLanzamiento = 25.0f; // El ángulo de lanzamiento de la bala, en grados
    float gravedad = -9.8f; // La gravedad que afecta a la bala, en unidades por segundo al cuadrado
    float tiempoVuelo = 0.0f; // El tiempo de vuelo de la bala, en segundos
    float posX;
    float posY;
    int direccion;

};
#endif // BALASEENEMIGOS_H
