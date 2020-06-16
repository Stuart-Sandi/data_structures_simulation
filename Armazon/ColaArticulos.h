#ifndef COLAARTICULOS_H
#define COLAARTICULOS_H
#include <articulo.h>


struct ColaArticulos{
    Articulo * frente, *final;
    QString nombre;
    ColaArticulos(QString n){
        this->frente = this->final = NULL;
        this->nombre = n;
    }
    // encabezados de funcion
    void encolar (Articulo*);
    Articulo * desencolar ();
    int cantidadEnCola();
    bool estaVacia();
};

#endif // COLAARTICULOS_H
