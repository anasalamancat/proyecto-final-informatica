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
#include "llegada.h"
#include "enemigo.h"

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
    int getcapa();
    bool getPasarNivel();
    void setPasarNivel(bool estado);
    void inicializarValores();

signals:
    void teclaSalto();
    void pasarDeNivel(bool);

public slots:
    void empezarSalto();
    void retornarAPosicionPrevialSalto();
    void caerPorGravedad();
    bool detectarColisionesPlataformas();
    bool detectarColisionesLlegada();

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
    bool colisionandoConPlataforma;
    bool avanzarArriba,avanzarAbajo,avanzarIzquierda,avanzarDerecha;

};

#endif // JUGADOR_H
