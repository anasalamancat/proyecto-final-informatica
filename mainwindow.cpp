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
    view = new QGraphicsView(scene, this);
    fondo= new background(":/pictures/garajeRick.png");
    timerColisiones= new QTimer();
    plataformas1=new obstaculos(":/pictures/plataformaPequena.png",200,40);
    plataformas2=new obstaculos(":/pictures/plataformaPequena.png",130,40);
    plataformas3=new obstaculos(":/pictures/plataformaPequena.png",140,40);
    plataformas4=new obstaculos(":/pictures/plataformaPequena.png",190,40);
    plataformas5=new obstaculos(":/pictures/plataformaPequena.png",150,40);
    plataformas6=new obstaculos(":/pictures/plataformaPequena.png",160,40);
    plataformas7=new obstaculos(":/pictures/plataformaPequena.png",150,40);
    plataformas8=new obstaculos(":/pictures/plataformaPequena.png",200,40);
    plataformas9=new obstaculos(":/pictures/plataformaPequena.png",130,40);

    llegada1= new llegada();
    ui->graphicsView->setScene(scene);

    scene->addItem(fondo);
    menuPrincipal();

    //connect(timerColisiones,&QTimer::timeout,this,&MainWindow::pasarNivel_1);
    connect(jugador1,SIGNAL(pasarDeNivel(bool)),this,SLOT(completarNivel(bool)));

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
    delete timerColisiones;
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
    scene->addItem(fondo);
    scene->addItem(jugador1);
    scene->addItem(plataformas1);
    scene->addItem(plataformas2);
    scene->addItem(plataformas3);
    scene->addItem(plataformas4);
    scene->addItem(plataformas5);
    scene->addItem(plataformas6);
    scene->addItem(plataformas7);
    scene->addItem(plataformas8);
    scene->addItem(plataformas9);

    scene->addItem(llegada1);
    jugador1->setPos(50,700);
    plataformas1->setPos(582,600);
    plataformas2->setPos(766,452);
    plataformas3->setPos(680,330);
    plataformas4->setPos(300,770);
    plataformas5->setPos(400,400);
    plataformas6->setPos(900,700);
    plataformas7->setPos(900,270);
    plataformas8->setPos(1030,200);
    llegada1->setPos(1100,90);
}

void MainWindow::nivel_2()
{
    scene->removeItem(plataformas1);
    scene->removeItem(plataformas2);
    jugador1->setPos(50,700);
    fondo->setPixmap(QPixmap(":/pictures/FondoSegundoNivel.png").scaled(1400,900));
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
        nivel_2();
    }
}

