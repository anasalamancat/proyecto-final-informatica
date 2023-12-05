#ifndef BALASENEMIGOS_H
#define BALASENEMIGOS_H
/*blas de los enemigos*/

#include <QObject>
#include "balas.h"

class balasEnemigos: public balas
{
    Q_OBJECT
public:
    balasEnemigos(); //construtor por defecto

public slots:
    /*metodo para mover la bala del enemigo segun la direccion*/
    void movBalaEnemiga(int _direccion);
};

#endif // BALASENEMIGOS_H
