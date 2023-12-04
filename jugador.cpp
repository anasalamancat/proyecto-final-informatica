#include "jugador.h"

jugador::jugador(QString direccion)
{
    Rick = new QGraphicsPixmapItem();
    setZValue(5);
    setPixmap(QPixmap(direccion).scaled(anchoCuerpo,largoCuerpo));
    timerSalto = new QTimer();
    timerColisiones = new QTimer();
    timerCaida= new QTimer();

    velocidadSalto=10;
    velDesplazamientoSalto=10;
    largoCuerpo = 162;
    anchoCuerpo = 125;
    contPasosDerecha=0;
    contPasosIzquierda=0;
    capa=5;
    colisionandoConPlataforma=false;
    estaEnSuelo==false;


    connect(this,&jugador::teclaSalto,this,&jugador::empezarSalto);
    connect(timerSalto,&QTimer::timeout,this,&jugador::retornarAPosicionPrevialSalto);
    connect(timerCaida,&QTimer::timeout,this,&jugador::caerPorGravedad);
    connect(timerColisiones,&QTimer::timeout,this,&jugador::detectarColisionesPlataformas);

    timerColisiones->start(10);

}

jugador::~jugador()
{
    delete Rick;
    delete timerSalto;
    delete timerColisiones;
    delete timerCaida;
}


void jugador::movementKeys(QKeyEvent *event)
{
    if(!this){
        return;
    }

    int currentX=this->x();
    int currentY=this->y();
    int newX,newY;
    int move=16;
    if(event->key()== Qt::Key_D){
        cambiarImagenDerecha();
        contPasosDerecha++;
        if(currentX<1285){
            newX=currentX+move;
            this->setX(newX);
            desplazamientoSaltoDerecha=true;
        }
    }
    else if(event->key()==Qt::Key_A){
        cambiarImagenIzquierda();
        contPasosIzquierda++;
        if(currentX>0){
            newX=currentX-move;
            this->setX(newX);
            desplazamientoSaltoIzquierda=true;
        }
    }
    else if(event->key()==Qt::Key_W && !timerSalto->isActive()&&currentY>16){
        timerCaida->stop();
        emit teclaSalto();
    }
    else if(event->key()==Qt::Key_S &&currentY<744){
        newY=currentY+move;
        this->setY(newY);
    }
    qDebug()<<this->x()<<","<<this->y();
}


void jugador::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_D){
        desplazamientoSaltoDerecha=false;
    }
    if(event->key()==Qt::Key_A){
        desplazamientoSaltoIzquierda=false;
    }
}


void jugador::cambiarImagenDerecha()
{
    if(contPasosDerecha==4){
        contPasosDerecha=0;
    }
    if(contPasosDerecha==0){
        setPixmap(QPixmap(":/pictures/rickderechaUnPie.png"));
    }
    if(contPasosDerecha==1 || contPasosDerecha==3){
        setPixmap(QPixmap(":/pictures/rickDrechaPiesjuntos.png"));
    }
    if(contPasosDerecha==2){
        setPixmap(QPixmap(":/pictures/rickDerechaOtropie.png"));
    }
}


void jugador::cambiarImagenIzquierda()
{
    if(contPasosIzquierda==4){
        contPasosIzquierda=0;
    }
    if(contPasosIzquierda==0){
        setPixmap(QPixmap(":/pictures/rickIzquierdaUnPie.png"));
    }
    if(contPasosIzquierda==1 || contPasosIzquierda==3){
        setPixmap(QPixmap(":/pictures/rickIzquierdaPiesjuntos.png"));
    }
    if(contPasosIzquierda==2){
        setPixmap(QPixmap(":/pictures/rickIzquierdaOtropie.png"));
    }
}

void jugador::verificarLadoColisionPlataformas(int platIzquierda, int platDerecha, int platArriba, int platAbajo)
{
    int currentX=this->x();
    int currentY=this->y();
    if((currentX+anchoCuerpo)==platIzquierda){
        avanzarDerecha==false;
    }
    if((currentX+anchoCuerpo)==platIzquierda && (currentY+largoCuerpo)>platArriba && currentY<platAbajo){
        avanzarDerecha=false;
    }


}

int jugador::getcapa()
{
    return capa;
}

void jugador::detectarColisiones()
{
    QList<QGraphicsItem *> colisiones= collidingItems();
    for(QGraphicsItem *i : colisiones){
        if(i && i!=this){
        //if(i->collidesWithItem(this)&& i){
            qDebug() <<"COLISION CONDICIONAL DETECTADA";
        }
    }
}

void jugador::caerPorGravedad()
{
    int currentY=this->y();
    if(colisionandoConPlataforma==false && currentY<744){
        timerCaida->start(100);
        this->setY(currentY+4);
    }
    if(currentY>730 && currentY<744){
        timerCaida->stop();
    }
}

void jugador::detectarColisionesPlataformas()
{
    QList<QGraphicsItem *> colisiones= collidingItems();

    for(QGraphicsItem *i : colisiones){
        obstaculos* obstaculoColision =dynamic_cast<obstaculos*>(i);

        if(obstaculoColision!=nullptr){
            int izquierda=obstaculoColision->getIzquierda();
            int derecha=obstaculoColision->getDerecha();
            int arriba=obstaculoColision->getArriba();
            int abajo=obstaculoColision->getAbajo();
            qDebug()<<"plataforma";
            colisionandoConPlataforma=true;
            verificarLadoColisionPlataformas(izquierda,derecha,arriba,abajo);
        }
        else{
            colisionandoConPlataforma=false;
        }
    }
}


void jugador::empezarSalto()
{
    posicionPreviaSalto=this->y();
    timerSalto->start(40);
}


void jugador::retornarAPosicionPrevialSalto()
{
    int nuevaPosY=this->y()-velocidadSalto;
    if(this->y()>16){
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

