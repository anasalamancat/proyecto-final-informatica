#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <background.h>
#include <QGraphicsView>
#include <rick.h>
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

private slots:
    void on_pushButtonEmpezar_clicked();

private:
    QTimer* timercol;
    Ui::MainWindow *ui;
    QTimer *timerColisiones;
    background* fondo;
    QGraphicsView *view;
    QGraphicsScene *scene;
    jugador *jugador1;
    obstaculos *plataformas1;
    obstaculos *plataformas2;
    obstaculos *plataformas3;
    obstaculos *plataformas4;
    obstaculos *plataformas5;
    obstaculos *plataformas6;
    llegada *llegada_;

};
#endif // MAINWINDOW_H
