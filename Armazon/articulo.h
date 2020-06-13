#ifndef ARTICULO_H
#define ARTICULO_H

#include <QString>

struct Articulo{

    QString codigo;
    int cantidad;
    int tiempoCreacion;
    QString categoria;
    QString ubicacion;
    Articulo * next, * before;
    bool estado;

    Articulo(){
        this->codigo = "";
        this->cantidad = 0;
        this->tiempoCreacion = 0;
        this->categoria = "";
        this->ubicacion = "";
        this->next = this->before = NULL;
        this->estado = false;
    }

    Articulo(QString pCodigo, int pCantidad, int pTiempo, QString pCategoria, QString pUbicacion){

        this->codigo = pCodigo;
        this->cantidad = pCantidad;
        this->tiempoCreacion = pTiempo;
        this->categoria = pCategoria;
        this->ubicacion = pUbicacion;
        this->next = this->before = NULL;

    }

};

#endif // ARTICULO_H
