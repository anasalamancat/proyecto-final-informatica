#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class background: public QObject, public QGraphicsPixmapItem
{
private:
    QGraphicsPixmapItem *backgroundImage;
    int capa;
public:
    background(QString direccion);
    ~background();
    int getcapa();
};

#endif // BACKGROUND_H
