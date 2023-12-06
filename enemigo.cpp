#include "enemigo.h"

enemigo::enemigo(QString direccion, int _velocidadDisparos)
{
    sprite=new QGraphicsPixmapItem();
    sprite->setPixmap(QPixmap(direccion).scaled(100,140));
    timerB = new QTimer(this);
    timerMove=new QTimer();
    connect(timerMove,SIGNAL(timeout()),this,SLOT(move()));
    connect(timerB, SIGNAL(timeout()), this, SLOT(disparar()));
    velocidadDisparos=_velocidadDisparos;
    enemy_direction_x = 1;
    ENEMY_SPEED_X = 5;
    timerB->start(velocidadDisparos);
    timerMove->start(45);

    setZValue(5);
}

enemigo::~enemigo()
{
    delete timerB;
    delete sprite;
    delete timerMove;
}
void enemigo::disparar(){
    emit agregarBala(true);
}

int enemigo::getPosY() const
{
    return this->y();
}

void enemigo::pararDisparos()
{
    timerB->stop();
}

int enemigo::getPosX() const
{
    return this->x();
}

int enemigo::getEnemy_direction_x() const
{
    return enemy_direction_x;
}

void enemigo::move(){
    // Mover el enemigo según la dirección y la velocidad en x
    setX(x() + enemy_direction_x * ENEMY_SPEED_X);

    // Si el enemigo llega al borde derecho de la escena, cambiar la dirección a izquierda y cambiar la posición en y
    if (x() + 100 > 1400){
        enemy_direction_x = -1;
        setPixmap(QPixmap(":/pictures/enemigoCaminandoIzquierda.png").scaled(100,140));
        setPos(x(), y()+100);
    }

    // Si el enemigo llega al borde izquierdo de la escena, cambiar la dirección a derecha y cambiar la posición en y
    if (x() < 0){
        enemy_direction_x = 1;
        setPixmap(QPixmap(":/pictures/enemigoCaminandoDerecha.png").scaled(100,140));
        setPos(x(), y()+100);
    }

    // Destruir el enemigo cuando salga de la escena por abajo
    if (y() > 744){
        //scene()->removeItem(this);
        delete this;
    }
}
