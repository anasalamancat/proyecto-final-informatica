#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "balas.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 1400)
            setPos(x()+10,y());
    }
    // move player up and
    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0)
            setPos(x(), y() -10);
    }
    else if(event->key() == Qt::Key_Down){
        if(pos().y()+100 < 900){
            setPos(x(), y()+10);
        }
    }

}

void Player::spawn(){
    // Crear un objeto de la clase enemigo
    Enemy * enemy = new Enemy();

    // Añadir el enemigo a la escena
    scene()->addItem(enemy);

}
