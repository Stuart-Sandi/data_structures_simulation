#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H
#include <pedido.h>
#include <QDebug>

struct ColaPedidos{
   Pedido * frente, *final;

   ColaPedidos(){
        this->frente = this->final = NULL;
   }

   // encabezados de funcion
   void encolar (Pedido*);
   Pedido * desencolar ();
   int cantidadEnCola();
   bool estaVacia();
   void imprimir();
};

#endif // COLAPEDIDOS_H
