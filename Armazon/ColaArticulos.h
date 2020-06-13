#ifndef COLAARTICULOS_H
#define COLAARTICULOS_H
#include <articulo.h>


struct ColaArticulos{
    Articulo * frente, *final;

    ColaArticulos(){
        this->frente = this->final = NULL;
    }
    // encabezados de funcion
    void encolar (Articulo*);
    Articulo * desencolar ();
    int cantidadEnCola();
    bool estaVacia();
};

#endif // COLAARTICULOS_H
