#ifndef LLEGADA_H
#define LLEGADA_H
#include <QObject>
#include <QGraphicsPixmapItem>


class llegada: public QGraphicsPixmapItem, public QObject
{
public:
    llegada();
    ~llegada();
private:
    QGraphicsPixmapItem *llegadaImagen;
};

#endif // LLEGADA_H
