#include "jugador.h"

jugador::jugador(QString direccion)
{
    Rick = new QGraphicsPixmapItem();
    setZValue(5);
    setPixmap(QPixmap(direccion).scaled(anchoCuerpo,largoCuerpo));
    timerSalto = new QTimer();
    timerColisiones = new QTimer();
    timerCaida= new QTimer();
    timerHerido=new QTimer();
    inicializarValores();

    connect(this,&jugador::teclaSalto,this,&jugador::empezarSalto);
    connect(timerSalto,&QTimer::timeout,this,&jugador::retornarAPosicionPrevialSalto);
    connect(timerCaida,&QTimer::timeout,this,&jugador::caerPorGravedad);
    connect(timerColisiones,&QTimer::timeout,this,&jugador::detectarColisionesPlataformas);
    connect(timerColisiones,&QTimer::timeout,this,&jugador::detectarColisionesLlegada);
    connect(timerHerido,&QTimer::timeout,this,&jugador::detectarColisionesEnemigos);
    connect(timerHerido,&QTimer::timeout,this,&jugador::detectarColisionesBalas);

    timerColisiones->start(10);
    timerHerido->start(20);
}

jugador::~jugador()
{
    delete Rick;
    delete timerSalto;
    delete timerColisiones;
    delete timerCaida;
    delete timerHerido;
}

void jugador::inicializarValores()
{
    velocidadSalto=16;
    velDesplazamientoSalto=16;
    largoCuerpo = 142;
    anchoCuerpo = 105;
    contPasosDerecha=0;
    contPasosIzquierda=0;
    colisionandoConPlataforma=false;
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
        timerCaida->start(18);
        cambiarImagenDerecha();
        contPasosDerecha++;
        if(currentX<1285){
            newX=currentX+move;
            this->setX(newX);
            desplazamientoSaltoDerecha=true;

    }
    }
    else if(event->key()==Qt::Key_A){
        timerCaida->start(18);
        cambiarImagenIzquierda();
        contPasosIzquierda++;
        if(currentX>0){
            newX=currentX-move;
            this->setX(newX);
            desplazamientoSaltoIzquierda=true;
        }
    }
    else if(event->key()==Qt::Key_W && !timerSalto->isActive()&& currentY>16 &&detectarColisionesPlataformas()==false){
        timerCaida->stop();
        emit teclaSalto();
    }
    else if(event->key()==Qt::Key_S &&currentY<744){
        newY=currentY+move;
        this->setY(newY);
    }
    timerHerido->start(20);

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



void jugador::caerPorGravedad()
{
    int currentY=this->y();
    if(detectarColisionesPlataformas()==false && currentY<744){
        timerCaida->start(18);
        this->setY(currentY+10);
    }
    else{
        timerCaida->stop();
        this->setY(currentY-8);
    }
}

bool jugador::detectarColisionesPlataformas()
{
    QList<QGraphicsItem *> colisiones= collidingItems();

    for(QGraphicsItem *i : colisiones){
        obstaculos* obstaculoColision =dynamic_cast<obstaculos*>(i);
        if(obstaculoColision!=nullptr){
            colisionandoConPlataforma=true;
            return true;
        }
        else{
            colisionandoConPlataforma=false;
            return false;
        }
    }
}

bool jugador::detectarColisionesLlegada()
{
    QList<QGraphicsItem *>colisiones=collidingItems();

    for(QGraphicsItem *i:colisiones){
        llegada* objetoColision=dynamic_cast<llegada*>(i);
        if(objetoColision!=nullptr){
            inicializarValores();
            emit pasarDeNivel(true);
            return true;
        }
        else{
                return false;
        }
    }
}

void jugador::detectarColisionesEnemigos()
{
    QList<QGraphicsItem *>colisiones=collidingItems();

    for(QGraphicsItem *i:colisiones){
        enemigo* objetoColision=dynamic_cast<enemigo*>(i);
        if(objetoColision!=nullptr){
                inicializarValores();
                emit colisionBalaOEnemigo(true);
                timerHerido->stop();
        }
    }
}

void jugador::detectarColisionesBalas()
{
    QList<QGraphicsItem *>colisiones=collidingItems();

    for(QGraphicsItem *i:colisiones){
        balasenemigos* objetoColision=dynamic_cast<balasenemigos*>(i);
        if(objetoColision!=nullptr){
            inicializarValores();
            emit colisionBalaOEnemigo(true);
            delete objetoColision;
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
        while(this->y()!=posicionPreviaSalto && detectarColisionesPlataformas()==false && this->y()<744){
                this->setY(this->y()+velocidadSalto);
        }
    }
}

