#ifndef OBSTACULOS_H
#define OBSTACULOS_H
#include <QVector>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <vector>
#include <QString>

class obstaculos:public QGraphicsPixmapItem, public QObject
{
private:
    QGraphicsPixmapItem *plataformas;
    int izquierda,derecha,arriba,abajo;
    int capa;
public:
    obstaculos(QString direccionImagen, int ancho,int alto);
    ~obstaculos();
    QRectF boundingRect()const override;
    int getcapa();
    int getIzquierda() const;
    int getDerecha() const;
    int getArriba() const;
    int getAbajo() const;
};

#endif // OBSTACULOS_H
