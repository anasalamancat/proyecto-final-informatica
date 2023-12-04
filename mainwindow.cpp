#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> graphicsView->setSceneRect(0,0,1400,900);

    jugador1 =new jugador(":/pictures/rickDeFrente.png");
    scene = new QGraphicsScene(this);
    timercol = new QTimer();
    view = new QGraphicsView(scene, this);
    fondo= new background(":/pictures/garajeRick.png");
    plataformas1=new obstaculos(":/pictures/plataformaPequena.png",200,40,500,230);
    plataformas2=new obstaculos(":/pictures/plataformaPequena.png",100,40,900,400);
    plataformas3=new obstaculos(":/pictures/plataformaPequena.png",240,40,600,40);
    plataformas4=new obstaculos(":/pictures/plataformaPequena.png",190,40,300,700);
    llegada1= new llegada();
    ui->graphicsView->setScene(scene);

    scene->addItem(fondo);
    menuPrincipal();

    //scene->addItem(plataformas2);
    //scene->addItem(plataformas3);
    //scene->addItem(plataformas4);

    //jugador1->setPos(100,700);
    //plataformas2->setPos(900,400);
    //plataformas3->setPos(600,40);
    //plataformas4->setPos(210,600);
    //plataformas1->setPos(500,230);
    //setCentralWidget(view);
    //scene->addItem(jugador1);
    //scene->addItem(plataformas1);
    //menuPrincipal();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete view;
    delete timerColisiones;
    delete jugador1;
    delete plataformas1;
    delete plataformas2;
    delete plataformas3;
    delete plataformas4;
    delete plataformas5;
    delete plataformas6;
    delete llegada1;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //character->movementKeys(event);
    jugador1->movementKeys(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    jugador1->keyReleaseEvent(event);
}

void MainWindow::nivel_1()
{
    fondo->setPixmap(QPixmap(":/pictures/garajeRick.png").scaled(1400,900));
    scene->addItem(fondo);
    scene->addItem(jugador1);
    scene->addItem(plataformas1);
    scene->addItem(plataformas2);
    scene->addItem(plataformas3);
    scene->addItem(plataformas4);
    scene->addItem(llegada1);
    jugador1->setPos(100,700);
    plataformas1->setPos(582,600);
    plataformas2->setPos(766,352);
    plataformas3->setPos(880,230);
    plataformas4->setPos(300,720);
    llegada1->setPos(1200,130);

}

void MainWindow::menuPrincipal()
{
    fondo->setPixmap(QPixmap(":/pictures/FondoMenu.PNG").scaled(1400,900));
    scene->setBackgroundBrush(Qt::black);
    ui->pushButtonEmpezar->setVisible(true);
    ui->pushButtonDinamica->setVisible(true);
}


void MainWindow::on_pushButtonEmpezar_clicked()
{
    ui->pushButtonDinamica->setVisible(false);
    ui->pushButtonEmpezar->setVisible(false);
    nivel_1();
}

