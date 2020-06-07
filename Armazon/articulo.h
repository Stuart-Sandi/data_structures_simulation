#ifndef ARTICULO_H
#define ARTICULO_H

#include <QString>

struct Articulo{

    QString codigo;
    int cantidad;

    Articulo(QString pCodigo, int pCantidad){

        this->codigo = pCodigo;
        this->cantidad = pCantidad;

    }

};

#endif // ARTICULO_H
