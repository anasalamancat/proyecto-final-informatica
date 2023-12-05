#include "balas.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "Enemy.h"
#include "juego.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet( float _posx, float _posy, int _direccion, tipoMovimiento _tipo, QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // drew the bullet (a rectangle)
    setRect(0,0,10,10);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(100);


    //timer movimiento circular
    QTimer *timerC = new QTimer(this);
    connect(timerC, SIGNAL(timeout()),this,SLOT(moveCircular()));
    timerC->start(100);

    QTimer *timerA = new QTimer(this);
    connect(timerA, SIGNAL(timeout()),this,SLOT(alternarMove()));
    timerA->start(48);

    tipoMovi = _tipo;
    posX = _posx;
    posY = _posy;
    direccion = _direccion;
    radioInicial = _posx;
    alturaInicial = _posy;
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    /*QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }*/

    float direccionBala = anguloLanzamiento * direccion;

    tiempoVuelo += 0.3f; // Puedes ajustar este valor según la frecuencia de actualización

    // Calcular la posición de la bala en x, usando la fórmula x = v * cos(a) * t
    // Donde v es la velocidad inicial, a es el ángulo de lanzamiento, y t es el tiempo de vuelo
    float x = velocidad * qCos(qDegreesToRadians(direccionBala)) * tiempoVuelo;

    // Calcular la posición de la bala en y, usando la fórmula y = v * sin(a) * t - 0.05 * g * t^2
    // Donde v es la velocidad inicial, a es el ángulo de lanzamiento, g es la gravedad, y t es el tiempo de vuelo
    float y = velocidad * qSin(qDegreesToRadians(direccionBala)) * tiempoVuelo - 0.5f * (gravedad*direccion) * tiempoVuelo * tiempoVuelo;

    posX += x*direccion;
    posY += y*direccion;

    // Establecer la posición de la bala según los valores calculados
    setPos(posX, posY);

    qDebug() << posX << "," << posY;


    // if the bullet is off the screen, destroy it
    if (pos().x() + rect().width() < 0 || pos().x() + rect().width() > 1400 || pos().y() > 900){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveCircular(){
    tiempoVuelo += 0.1f; // Ajusta la frecuencia de actualización según sea necesario

    // Calcular la nueva posición de la bala para el movimiento circular
    anguloC += velocidadAngular * tiempoVuelo;
    float xCircular = radio * qSin(anguloC);
    float yCircular = radio * qCos(anguloC);

    // Calcular la caída debida a la gravedad
    float caida = 0.5f * gravedad * tiempoVuelo * tiempoVuelo;

    // Actualizar la posición de la bala
    posX = radioInicial + xCircular * direccion;
    posY = alturaInicial - caida + yCircular;

    // Establecer la nueva posición de la bala
    setPos(posX, posY);

    // Ajustar las condiciones de eliminación
    if (pos().x() > 1400 || pos().x() + rect().width() < 0 || pos().y() > 900){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::alternarMove() {
    if (tipoMovi == Parabolico) {
        move();
    }
    else/* if (tipoMovi == Circular) */{
        moveCircular();
    }
}
