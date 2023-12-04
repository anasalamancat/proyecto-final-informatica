#include "background.h"

background::background(QString direccion)
{
    backgroundImage=new QGraphicsPixmapItem();
    setZValue(1);
    setPixmap(QPixmap(direccion).scaled(1400,900));

}

background::~background()
{
    delete backgroundImage;
}

int background::getcapa()
{
    return capa;
}
