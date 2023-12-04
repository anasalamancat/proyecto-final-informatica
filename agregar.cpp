#include "agregar.h"


agregar::agregar(QString direccion, int ancho, int largo)
{
    setPixmap(QPixmap(direccion).scaled(ancho,largo));
}

Tipo agregar::getTipo()
{
    return tipoObjeto;
}

void agregar::setTipo(Tipo nuevoTipo)
{
    tipoObjeto=nuevoTipo;
}

