#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "juego.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    //set random x position
    int random_number = rand() % 800;
    setPos(random_number,450);

    // drew the rect
    setRect(0,0,100,200);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //connect(this, SIGNAL(collision(QGraphicsItem*)), this, SLOT(colision(QGraphicsItem*)));

    // start the timer
    timer->start(50);

    timerB = new QTimer(this);
    connect(timerB, SIGNAL(timeout()), this, SLOT(disparar()));
    timerB -> start(3000);
}

int enemy_direction_x = 1;
int ENEMY_SPEED_X = 5;


//void Enemy::disparar(){
    //Bullet* bullet = new Bullet(pos().x(), pos().y(), enemy_direction_x);
    //bullet->setPos(this->pos().x()+100*enemy_direction_x, this->pos().y()+20);
  //  scene()->addItem(bullet);
//}


void Enemy::move(){
    // Mover el enemigo según la dirección y la velocidad en x
    setX(x() + enemy_direction_x * ENEMY_SPEED_X);

    // Si el enemigo llega al borde derecho de la escena, cambiar la dirección a izquierda y cambiar la posición en y
    if (x() + 100 > 1400){
        enemy_direction_x = -1;
        setPos(x(), y()+100);
    }

    // Si el enemigo llega al borde izquierdo de la escena, cambiar la dirección a derecha y cambiar la posición en y
    if (x() < 0){
        enemy_direction_x = 1;
        setPos(x(), y()+100);
    }

    // Destruir el enemigo cuando salga de la escena por abajo
    if (pos().y() > 900){
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::disparar(){

    static bool alternar = true; // Variable estática para alternar entre movimientos
    tipoMovimiento tipo = alternar ? Parabolico : Circular;
    Bullet* bullet = new Bullet(pos().x(), pos().y(), enemy_direction_x, tipo);
    scene()->addItem(bullet);
    alternar = !alternar; // Cambiar el estado para la próxima bala
}

Enemy::~Enemy(){
    delete timerB;
}


