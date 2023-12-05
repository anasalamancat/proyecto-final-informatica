#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <background.h>
#include <QGraphicsView>
#include <rick.h>
#include <QDebug>
#include "obstaculos.h"
#include "jugador.h"
#include "llegada.h"

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

private slots:
    void on_pushButtonEmpezar_clicked();
    void completarNivel(bool NivelCompletado);

private:
    Ui::MainWindow *ui;
    QTimer *timerColisiones;
    background* fondo;
    QGraphicsView *view;
    QGraphicsScene *scene;
    jugador *jugador1;
    QGraphicsPixmapItem *caraRick;
    QGraphicsPixmapItem *porcentajeVida;
    obstaculos *plataformas1;
    obstaculos *plataformas2;
    obstaculos *plataformas3;
    obstaculos *plataformas4;
    obstaculos *plataformas5;
    obstaculos *plataformas6;
    obstaculos *plataformas7;
    obstaculos *plataformas8;
    obstaculos *plataformas9;
    llegada *llegada1;
    int nivelActual;

};
#endif // MAINWINDOW_H
