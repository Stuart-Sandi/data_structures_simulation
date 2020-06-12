#ifndef COLAPEDIDOS_H
#define COLAPEDIDOS_H
#include <NodoColaPedido.h>

struct ColaPedidos{
   NodoPedido * frente, *final;

   ColaPedidos(){
        this->frente = this->final = NULL;
   }

   // encabezados de funcion
   void encolar (Pedido*);
   NodoPedido * desencolar ();
   int cantidadEnCola();
   bool estaVacia();
};

#endif // COLAPEDIDOS_H
