#ifndef JUGADOR_H
#define JUGADOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QString>
#include <QGraphicsView>
#include "obstaculos.h"

class jugador: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    jugador(QString direccion);
    ~jugador();
    void movementKeys(QKeyEvent *event=nullptr);
    void keyReleaseEvent(QKeyEvent *event)override;
    void movement(QString direccionActual);
    void cambiarImagenDerecha();
    void cambiarImagenIzquierda();
    void verificarLadoColisionPlataformas(int platIzquierda,int platDerecha, int platArriba, int platAbajo);
    int getcapa();

signals:
    void teclaSalto();

public slots:
    void empezarSalto();
    void retornarAPosicionPrevialSalto();
    void detectarColisiones();
    void caerPorGravedad();
    void detectarColisionesPlataformas();

private:
    QGraphicsPixmapItem *Rick;
    QTimer* timerSalto;
    QTimer* timerColisiones;
    QTimer* timerCaida;

    float anchoCuerpo;
    float largoCuerpo;
    bool desplazamientoSaltoDerecha;
    bool desplazamientoSaltoIzquierda;
    int velocidadSalto;
    int velDesplazamientoSalto;
    int posicionPreviaSalto;
    int contPasosIzquierda;
    int contPasosDerecha;
    int capa;
    bool colisionandoConPlataforma;
    bool estaEnSuelo;
    bool avanzarArriba,avanzarAbajo,avanzarIzquierda,avanzarDerecha;

};

#endif // JUGADOR_H
