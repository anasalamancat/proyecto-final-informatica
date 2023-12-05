#include "balasenemigos.h"

balasenemigos::balasenemigos( float _posx, float _posy, int _direccion, QString direccion){
    imagenBala= new QGraphicsPixmapItem();
    timerBalas=new QTimer();
    connect(timerBalas,&QTimer::timeout,this,&balasenemigos::move);
    timerBalas->start(70);
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
