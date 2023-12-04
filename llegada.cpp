#include "llegada.h"

llegada::llegada()
{
    llegadaImagen= new QGraphicsPixmapItem;
    setPixmap(QPixmap(":/pictures/puertaLlegada.png").scaled(90,110));
}

llegada::~llegada()
{
    delete llegadaImagen;
}
