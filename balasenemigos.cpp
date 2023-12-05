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
    int currentX=this->x();
    float newX;
    float direccionBala = anguloLanzamiento * direccion;

    tiempoVuelo += 0.1f;
    float Posx = velocidad * qCos(qDegreesToRadians(direccionBala)) * tiempoVuelo;
    float Posy = velocidad * qSin(qDegreesToRadians(direccionBala)) * tiempoVuelo - 0.5f * gravedad * tiempoVuelo * tiempoVuelo;

    if(direccion=1){
        newX = Posx + posX;
    }
    if(direccion==-1){
        newX = Posx - posX;
    }
    float newY = Posy + posY;

    this->setPos(newX,newY);

    // si la bala sale de la escena
    if (currentX + 50 < 0 || currentX + 50 > 1400 ){
        delete this;
    }
}
