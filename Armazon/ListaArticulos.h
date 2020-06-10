#ifndef LISTAARTICULOS_H
#define LISTAARTICULOS_H
#include <articulo.h>
#include<QDebug>

struct ListaArticulos{
    Articulo * primerNodo, * ultimoNodo;
    ListaArticulos(){
        this->primerNodo = NULL;
        this->ultimoNodo = NULL;
    }
    //DECLARACION DE FUNCIONES
    int insertarArticulo(Articulo*);
    Articulo * buscarArticulo(QString);
    void imprimir();
};

#endif // LISTAARTICULOS_H
