#include "rick.h"

rick::rick()
{
    rickBody = new QPixmap();
    //rickBody= new QGraphicsPixmapItem();
    //setPixmap(QPixmap(":/pictures/rickDeFrente.png").scaled(largoCuerpo,anchoCuerpo));
    timerSalto = new QTimer();

    velocidadSalto=10;
    velDesplazamientoSalto=10;
    largoCuerpo = 162;
    anchoCuerpo = 125;

    columnsBody = 0;
    this->setPos(600,400);

    connect(this,&rick::teclaSalto,this,&rick::empezarSalto);
    connect(timerSalto,&QTimer::timeout,this,&rick::retornarAPosicionPrevialSalto);
}

rick::~rick()
{
    delete timerSalto;
    delete rickBody;
}


void rick::splitSprite(QString direccion)
{
    QPixmap torsoAux(direccion);
    *rickBody = torsoAux.copy(columnsBody,rowsBody,anchoCuerpo,largoCuerpo);

}

void rick::update()
{
    columnsBody += anchoCuerpo;
    if(columnsBody >= 500){
       columnsBody = 0;
    }
}

void rick::movementKeys(QKeyEvent *event)
{
    if(!this){
       return;
    }

    int currentX=this->x();
    int currentY=this->y();
    int newX,newY;
    int move=16;
    if(event->key()== Qt::Key_D ){
       movement(":/pictures/rickLadoDerechoVector.png");
       if(currentX<1285){
           newX=currentX+move;
           this->setX(newX);
           desplazamientoSaltoDerecha=true;
       }
    }
    else if(event->key()==Qt::Key_A){
       movement(":/pictures/rickLadoIzquierdoVector.png");
       if(currentX>0){
           newX=currentX-move;
           this->setX(newX);
           desplazamientoSaltoIzquierda=true;
       }
    }
    else if(event->key()==Qt::Key_W && !timerSalto->isActive()&&currentY>16){
       splitSprite(":/pictures/rickDeFrente.png");
       emit teclaSalto();
    }
    else if(event->key()==Qt::Key_S &&currentY<744){
       splitSprite(":/pictures/rickDeFrente.png");
       newY=currentY+move;
       this->setY(newY);
    }
    qDebug()<<this->x()<<","<<this->y();
}

void rick::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D){
       desplazamientoSaltoDerecha=false;
    }
    if(event->key()==Qt::Key_A){
       desplazamientoSaltoIzquierda=false;
    }
}

void rick::movement(QString direccionActual)
{
    update();
    splitSprite(direccionActual);
    setPixmap(*rickBody);
}

void rick::empezarSalto()
{
    posicionPreviaSalto=this->y();
    timerSalto->start(40);
}

void rick::retornarAPosicionPrevialSalto()
{
    int nuevaPosY=this->y()-velocidadSalto;
    if(this->y()>6){
    this->setY(nuevaPosY);
    }
    if(desplazamientoSaltoDerecha==true && this->x()<1285 && this->x()>0){
       int nuevaPosX=this->x()+velDesplazamientoSalto;
       this->setX(nuevaPosX);
    }
    if(desplazamientoSaltoIzquierda==true && this->x()<1285 && this->x()>0){
       int nuevaposX=this->x()-velDesplazamientoSalto;
       this->setX(nuevaposX);
    }

    if(nuevaPosY<=posicionPreviaSalto-150 || this->y()<8){
       timerSalto->stop();
       this->setY(posicionPreviaSalto-50);
    }
}




