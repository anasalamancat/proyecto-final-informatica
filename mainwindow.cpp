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
    porcentajeVida=new QGraphicsPixmapItem(QPixmap(":/pictures/3corazones.png").scaled(150,150));
    llegada1= new llegada();

    cantidadVidas=3;
    random_numberX = rand() % 1000;


    plataformas1=new obstaculos(":/pictures/plataformaPequena.png",200,40);
    plataformas2=new obstaculos(":/pictures/plataformaPequena.png",170,40);
    plataformas3=new obstaculos(":/pictures/plataformaPequena.png",180,40);
    plataformas4=new obstaculos(":/pictures/plataformaPequena.png",190,40);
    plataformas5=new obstaculos(":/pictures/plataformaPequena.png",150,40);
    plataformas6=new obstaculos(":/pictures/plataformaPequena.png",160,40);
    plataformas7=new obstaculos(":/pictures/plataformaPequena.png",180,40);
    plataformas8=new obstaculos(":/pictures/plataformaPequena.png",200,40);
    plataformas9=new obstaculos(":/pictures/plataformaPequena.png",170,40);

    enemigo1=new enemigo(":/pictures/enemigoCaminandoDerecha.png",5000);
    enemigo2=new enemigo(":/pictures/enemigoCaminandoDerecha.png",5000);
    enemigo3=new enemigo(":/pictures/enemigoCaminandoDerecha.png",3000);
    enemigo4=new enemigo(":/pictures/enemigoCaminandoDerecha.png",2500);

    ui->graphicsView->setScene(scene);

    scene->addItem(fondo);
    menuPrincipal();

    connect(jugador1,SIGNAL(pasarDeNivel(bool)),this,SLOT(completarNivel(bool)));
    connect(enemigo1,SIGNAL(agregarBala(bool)),this,SLOT(enemigo1Dispara(bool)));
    connect(jugador1,SIGNAL(colisionBalaOEnemigo(bool)),this,SLOT(jugadorHerido(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete view;
    delete jugador1;
    delete plataformas1;
    delete plataformas2;
    delete plataformas3;
    delete plataformas4;
    delete plataformas5;
    delete plataformas6;
    delete llegada1;
    delete caraRick;
    delete porcentajeVida;
    delete enemigo1;
    delete enemigo2;
    delete enemigo3;
    delete enemigo4;

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
    ui->lineEdit->setVisible(true);
    scene->setBackgroundBrush(Qt::green);
    fondo->setPixmap(QPixmap(":/pictures/FondoPrimerNivel.png").scaled(1400,900));
    caraRick->setPixmap(QPixmap(":/pictures/caraRick.png").scaled(100,100));
    jugador1->setPixmap(QPixmap(":/pictures/rickDeFrente.png").scaled(105,142));
    enemigo1->setPixmap(QPixmap(":/pictures/enemigoCaminandoDerecha.png").scaled(100,140));
    caraRick->setZValue(5);
    porcentajeVida->setZValue(5);
    scene->addItem(fondo);
    scene->addItem(jugador1);
    scene->addItem(caraRick);
    scene->addItem(plataformas3);
    scene->addItem(plataformas4);
    scene->addItem(plataformas5);
    scene->addItem(plataformas6);
    scene->addItem(plataformas7);
    scene->addItem(porcentajeVida);
    scene->addItem(llegada1);
    scene->addItem(enemigo1);
    jugador1->setPos(1170,60);
    caraRick->setPos(70,10);
    porcentajeVida->setPos(150,15);
    plataformas3->setPos(560,580);
    plataformas4->setPos(300,770);
    plataformas5->setPos(970,630);
    plataformas6->setPos(900,410);
    plataformas7->setPos(1130,270);
    llegada1->setPos(30,750);
    enemigo1->setPos(random_numberX,200);
}

void MainWindow::nivel_2()
{
    enemigo2->setPixmap(QPixmap(":/pictures/enemigoCaminandoDerecha.png").scaled(100,140));
    scene->addItem(enemigo2);
    enemigo2->setPos(random_numberX+500,400);
    fondo->setPixmap(QPixmap(":/pictures/FondoSegundoNivel.png").scaled(1400,900));
    plataformas1->setPos(600,650);
    plataformas2->setPos(800,512);
    plataformas3->setPos(560,380);
    llegada1->setPos(1170,50);
}

void MainWindow::nivel_3()
{
    enemigo3->setPixmap(QPixmap(":/pictures/enemigoCaminandoDerecha.png").scaled(100,140));
    enemigo3->setPos(random_numberX,300);
    scene->addItem(enemigo3);
    enemigo4->setPos(random_numberX,400);
    enemigo4->setPixmap(QPixmap(":/pictures/enemigoCaminandoDerecha.png").scaled(100,140));
    scene->addItem(enemigo4);
    fondo->setPixmap(QPixmap(":/pictures/garajeRick.png").scaled(1400,900));
    llegada1->setPos(40,150);
}

void MainWindow::eliminarElementos()
{
    scene->removeItem(plataformas1);
    scene->removeItem(plataformas2);
    scene->removeItem(plataformas3);
    scene->removeItem(plataformas4);
    scene->removeItem(plataformas5);
    scene->removeItem(plataformas6);
    scene->removeItem(plataformas7);
    scene->removeItem(plataformas8);
    scene->removeItem(plataformas9);
    scene->removeItem(jugador1);
    scene->removeItem(llegada1);
    scene->removeItem(enemigo1);
    scene->removeItem(enemigo2);
    scene->removeItem(enemigo3);
    scene->removeItem(enemigo4);
    scene->removeItem(caraRick);
    scene->removeItem(porcentajeVida);
}

void MainWindow::menuPrincipal()
{
    fondo->setPixmap(QPixmap(":/pictures/FondoMenu.PNG").scaled(1400,900));
    scene->setBackgroundBrush(Qt::black);
    ui->pushButtonEmpezar->setVisible(true);
    ui->pushButtonDinamica->setVisible(true);
    ui->pushButtongGameOver->setVisible(false);
    ui->lineEdit->setVisible(false);
}


void MainWindow::on_pushButtonEmpezar_clicked()
{
    ui->pushButtonDinamica->setVisible(false);
    ui->pushButtonEmpezar->setVisible(false);
    nivel_1();
}

void MainWindow::on_pushButtongGameOver_clicked()
{
    menuPrincipal();
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

void MainWindow::enemigo1Dispara(bool Disparar)
{
    qDebug()<<Disparar;
    if(Disparar){
        int direccion=enemigo1->getEnemy_direction_x();
        int posX= enemigo1->getPosX();
        int posY=enemigo1->getPosY();
        balasenemigos* bullet = new balasenemigos(posX,posY, direccion,":/pictures/balaa.png");
        bullet->setPixmap(QPixmap(":/pictures/balaa.png").scaled(70,70));
        scene->addItem(bullet);
        bullet->setPos(posX+(direccion*100),posY+20);
    }

}

void MainWindow::jugadorHerido(bool herido)
{
    cantidadVidas--;
    if(herido){
        if(cantidadVidas==2){
            porcentajeVida->setPixmap(QPixmap(":/pictures/2corazones.png").scaled(120,150));
            scene->setBackgroundBrush(Qt::yellow);
        }
        if(cantidadVidas==1){
            porcentajeVida->setPixmap(QPixmap(":/pictures/1corazon.png").scaled(100,150));
            scene->setBackgroundBrush(Qt::red);
        }
        if(cantidadVidas==0){
            eliminarElementos();
            fondo->setPixmap(QPixmap(":/pictures/gameover.jpg").scaled(1400,900));
            ui->pushButtongGameOver->setVisible(true);
        }
    }
}



