#include "balasenemigos.h"

balasenemigos::balasenemigos( float _posx, float _posy, int _direccion, QString direccion,tipoMovimiento tipo){
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
    tipoMovi=tipo;
    direccion = _direccion;
    radioInicial = _posx;
    alturaInicial = _posy;
}

balasenemigos::~balasenemigos()
{
    delete timerBalas;
    delete imagenBala;
    delete timerA;
    delete timerC;
}

void balasenemigos::move(){
    float direccionBala = anguloLanzamiento * direccion;

    tiempoVuelo += 0.3f;
    float x = velocidad * qCos(qDegreesToRadians(direccionBala)) * tiempoVuelo;
    float y = velocidad * qSin(qDegreesToRadians(direccionBala)) * tiempoVuelo - 0.5f * gravedad * tiempoVuelo * tiempoVuelo;
    posX = x *direccion;
    posY = y * direccion;
    setPos(posX, posY);

    if (this->x() + 50 < 0 || this->x() + 50 > 1400 ||this->y()>744){
        delete this;
    }
}

void balasenemigos::alternarMove()
{
    if (tipoMovi == Parabolico) {
        move();
    }
    else{
        moveCircular();

    }
}

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
