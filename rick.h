#ifndef RICK_H
#define RICK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QString>
#include <QGraphicsView>

class rick: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPixmap * rickBody;
    //QGraphicsPixmapItem *rickBody;
    QTimer* timerSalto;

    float anchoCuerpo, largoCuerpo;
    float rowsBody, columnsBody;
    bool desplazamientoSaltoDerecha,desplazamientoSaltoIzquierda;
    int velocidadSalto,velDesplazamientoSalto,posicionPreviaSalto;

public:
    rick();
    ~rick();
    void splitSprite(QString direccion);
    void update();
    void movementKeys(QKeyEvent *event=nullptr);
    void keyReleaseEvent(QKeyEvent *event)override;
    void movement(QString direccionActual);

signals:
    void teclaSalto();

public slots:
    void empezarSalto();
    void retornarAPosicionPrevialSalto();

};

#endif // RICK_H



