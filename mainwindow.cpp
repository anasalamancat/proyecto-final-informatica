#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui-> graphicsView->setSceneRect(0,0,1400,900);
    nivelActual=0;
    jugador1 =new jugador(":/pictures/rickDeFrente.png");
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    fondo= new background(":/pictures/garajeRick.png");
    caraRick= new QGraphicsPixmapItem();
    porcentajeVida=new QGraphicsPixmapItem(QPixmap(":/pictures/3vidas.jpg").scaled(131,40));
    timerColisiones= new QTimer();

    plataformas1=new obstaculos(":/pictures/plataformaPequena.png",200,40);
    plataformas2=new obstaculos(":/pictures/plataformaPequena.png",170,40);
    plataformas3=new obstaculos(":/pictures/plataformaPequena.png",140,40);
    plataformas4=new obstaculos(":/pictures/plataformaPequena.png",190,40);
    plataformas5=new obstaculos(":/pictures/plataformaPequena.png",150,40);
    plataformas6=new obstaculos(":/pictures/plataformaPequena.png",160,40);
    plataformas7=new obstaculos(":/pictures/plataformaPequena.png",180,40);
    plataformas8=new obstaculos(":/pictures/plataformaPequena.png",200,40);
    plataformas9=new obstaculos(":/pictures/plataformaPequena.png",170,40);

    llegada1= new llegada();
    ui->graphicsView->setScene(scene);

    scene->addItem(fondo);
    menuPrincipal();

    connect(jugador1,SIGNAL(pasarDeNivel(bool)),this,SLOT(completarNivel(bool)));
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
    delete timerColisiones;
    delete caraRick;
    delete porcentajeVida;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    jugador1->movementKeys(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    jugador1->keyReleaseEvent(event);
}

void MainWindow::nivel_1()
{
    fondo->setPixmap(QPixmap(":/pictures/FondoPrimerNivel.png").scaled(1400,900));
    caraRick->setPixmap(QPixmap(":/pictures/caraRick.png").scaled(70,70));
    caraRick->setZValue(5);
    porcentajeVida->setZValue(5);
    scene->addItem(fondo);
    scene->addItem(jugador1);
    scene->addItem(caraRick);
    scene->addItem(plataformas1);
    scene->addItem(plataformas2);
    scene->addItem(plataformas3);
    scene->addItem(plataformas4);
    scene->addItem(plataformas5);
    scene->addItem(plataformas6);
    scene->addItem(plataformas7);
    scene->addItem(porcentajeVida);
    scene->addItem(llegada1);
    jugador1->setPos(50,700);
    caraRick->setPos(70,10);
    plataformas1->setPos(600,650);
    plataformas2->setPos(800,512);
    plataformas3->setPos(560,380);
    plataformas4->setPos(300,770);
    plataformas5->setPos(970,630);
    plataformas6->setPos(900,270);
    plataformas7->setPos(1130,170);
    llegada1->setPos(1170,60);
    porcentajeVida->setPos(150,15);
}

void MainWindow::nivel_2()
{
    scene->removeItem(plataformas1);
    scene->removeItem(plataformas2);
    llegada1->setPos(20,730);
    fondo->setPixmap(QPixmap(":/pictures/FondoSegundoNivel.png").scaled(1400,900));
}

void MainWindow::nivel_3()
{
    fondo->setPixmap(QPixmap(":/pictures/garajeRick.png").scaled(1400,900));
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

void MainWindow::completarNivel(bool NIvelCompletado)
{
    if(NIvelCompletado){
        nivelActual++;
        if(nivelActual==1){
            nivel_2();
        }
        if(nivelActual==2){
            nivel_3();
        }
    }
}

