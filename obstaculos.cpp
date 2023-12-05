#include "obstaculos.h"


obstaculos::obstaculos(QString direccionImagen,int ancho, int alto)
{
    plataformas=new QGraphicsPixmapItem();
    setZValue(4);
    setPixmap(QPixmap(direccionImagen).scaled(ancho,alto));
}

obstaculos::~obstaculos()
{
    delete plataformas;
}

QRectF obstaculos::boundingRect() const
{
    return QRectF(0,0,pixmap().width(),pixmap().height());
}

int obstaculos::getcapa()
{
    return capa;
}
