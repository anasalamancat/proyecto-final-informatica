#include "balasenemigos.h"

balasenemigos::balasenemigos( float _posx, float _posy, int _direccion, QString direccion){
    imagenBala= new QGraphicsPixmapItem();
    timerBalas=new QTimer();
    connect(timerBalas,&QTimer::timeout,this,&balasenemigos::move);
    timerBalas->start(70);

    //timerC = new QTimer(this);
    //connect(timerC, &QTimer::timeout,this,&balasenemigos::moveCircular);

    //timerA = new QTimer(this);
    //connect(timerA, &QTimer::timeout,this,&balasenemigos::alternarMove);
    //timerA->start(100);
    //timerC->start(100);

    setZValue(5);
    posX = _posx;
    posY = _posy;
    direccion = _direccion;
}

balasenemigos::~balasenemigos()
{
    delete timerBalas;
    delete imagenBala;
}

void balasenemigos::move(){
    float direccionBala = anguloLanzamiento * direccion;

    tiempoVuelo += 0.3f; // Puedes ajustar este valor según la frecuencia de actualización

    float x = velocidad * qCos(qDegreesToRadians(direccionBala)) * tiempoVuelo;
    float y = velocidad * qSin(qDegreesToRadians(direccionBala)) * tiempoVuelo - 0.5f * gravedad * tiempoVuelo * tiempoVuelo;

    float newX = x + posX;
    float newY = y + posY;

    setPos(newX, newY);

    // si la bala sale de la escena
    if (newX + 50 < 0 || newX + 50 > 1400 ||newY>744){
        delete this;
    }
}
/*
void balasenemigos::moveCircular()
{
    tiempoVuelo += 0.1f;
    anguloC += velocidadAngular * tiempoVuelo;
    float xCircular = radio * qSin(anguloC);
    float yCircular = radio * qCos(anguloC);
    float caida = 0.5f * gravedad * tiempoVuelo * tiempoVuelo;
    posX = radioInicial + xCircular * direccion;
    posY = alturaInicial - caida + yCircular;
    setPos(posX, posY);
    if (this->x() > 1400 || this->x() < 0 || this->y() > 900){
        delete this;
    }
}
*/
