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
    plataformas1=new obstaculos(":/pictures/plataformaPequena.png",300,40,500,230);
    plataformas2=new obstaculos(":/pictures/plataformaPequena.png",200,40,900,400);
    plataformas3=new obstaculos(":/pictures/plataformaPequena.png",100,40,600,40);
    plataformas4=new obstaculos(":/pictures/plataformaPequena.png",190,40,210,600);

    ui->graphicsView->setScene(scene);

    scene->addItem(fondo);
    scene->addItem(plataformas2);
    scene->addItem(plataformas3);
    scene->addItem(plataformas4);

    jugador1->setPos(100,700);
    plataformas2->setPos(900,400);
    plataformas3->setPos(600,40);
    plataformas4->setPos(210,600);
    plataformas1->setPos(500,230);
    //setCentralWidget(view);
    scene->addItem(jugador1);
    scene->addItem(plataformas1);
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

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //character->movementKeys(event);
    jugador1->movementKeys(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    //character->keyReleaseEvent(event);
    jugador1->keyReleaseEvent(event);
}

void MainWindow::nivel_1()
{
    plataformas1=new obstaculos(":/pictures/plataformaPequena.png",300,40,500,230);
    plataformas2=new obstaculos(":/pictures/plataformaPequena.png",200,40,900,400);
    plataformas3=new obstaculos(":/pictures/plataformaPequena.png",100,40,600,40);
    plataformas4=new obstaculos(":/pictures/plataformaPequena.png",190,40,100,800);
    fondo->setPixmap(QPixmap(":/pictures/garajeRick.png").scaled(1400,900));
    scene->addItem(fondo);
    scene->addItem(plataformas1);
    scene->addItem(plataformas2);
    scene->addItem(plataformas3);
    scene->addItem(plataformas4);
    jugador1->setPos(100,100);
    plataformas1->setPos(500,230);
    plataformas2->setPos(900,400);
    plataformas3->setPos(600,40);
    plataformas4->setPos(100,800);

}

void MainWindow::menuPrincipal()
{
    scene->setBackgroundBrush(QPixmap(":/pictures/FondoMenu.PNG").scaled(1400,900));
    ui->pushButtonEmpezar->setVisible(true);
    ui->pushButtonDinamica->setVisible(true);
}

