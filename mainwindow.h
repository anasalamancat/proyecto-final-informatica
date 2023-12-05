#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <background.h>
#include <QGraphicsView>
#include <QDebug>
#include <QLabel>
#include "jugador.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void menuPrincipal();
    void nivel_1();
    void nivel_2();
    void nivel_3();
    void eliminarElementos();
;

private slots:
    void on_pushButtonEmpezar_clicked();
    void completarNivel(bool NivelCompletado);
    void enemigo1Dispara(bool Disparar);
    void jugadorHerido(bool herido);
    void on_pushButtongGameOver_clicked();

    void on_pushButtonDinamica_clicked();

private:
    Ui::MainWindow *ui;
    background* fondo;
    QGraphicsView *view;
    QGraphicsScene *scene;
    jugador *jugador1;
    QGraphicsPixmapItem *caraRick;
    QGraphicsPixmapItem *porcentajeVida;
    QGraphicsPixmapItem *dinamica;
    obstaculos *plataformas1;
    obstaculos *plataformas2;
    obstaculos *plataformas3;
    obstaculos *plataformas4;
    obstaculos *plataformas5;
    obstaculos *plataformas6;
    obstaculos *plataformas7;
    obstaculos *plataformas8;
    obstaculos *plataformas9;
    enemigo *enemigo1;
    enemigo *enemigo2;
    enemigo *enemigo3;
    enemigo *enemigo4;
    llegada *llegada1;
    int nivelActual;
    int random_numberX;
    int cantidadVidas;

};
#endif // MAINWINDOW_H
