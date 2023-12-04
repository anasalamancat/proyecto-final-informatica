#include "obstaculos.h"


obstaculos::obstaculos(QString direccionImagen,int ancho, int alto, int xo, int yo)
{
    plataformas=new QGraphicsPixmapItem();
    setZValue(5);
    setPixmap(QPixmap(direccionImagen).scaled(ancho,alto));
    izquierda=xo;
    arriba=yo;
    derecha=xo+ancho;
    abajo=yo+alto;
}

obstaculos::~obstaculos()
{
    delete plataformas;
}

int obstaculos::getIzquierda() const
{
    return izquierda;
}

int obstaculos::getDerecha() const
{
    return derecha;
}

int obstaculos::getArriba() const
{
    return arriba;
}

int obstaculos::getAbajo() const
{
    return abajo;
}

QRectF obstaculos::boundingRect() const
{
    return QRectF(0,0,pixmap().width(),pixmap().height());
}

int obstaculos::getcapa()
{
    return capa;
}
