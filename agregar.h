#ifndef AGREGAR_H
#define AGREGAR_H
#include <QGraphicsProxyWidget>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTextEdit>

enum class Tipo{Borde,Plataforma,Enemigo,Bala};

class agregar: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    agregar(QString direccion,int ancho, int largo);
    Tipo getTipo();
    void setTipo(Tipo nuevoTipo);
private:
    Tipo tipoObjeto;
};

#endif // AGREGAR_H
