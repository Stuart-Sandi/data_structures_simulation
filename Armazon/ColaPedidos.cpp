#include "ColaPedidos.h"

void ColaPedidos::encolar(Pedido * pDato){
    NodoPedido * nuevo = new NodoPedido(pDato);
    if (this->estaVacia()){
        this->final = this->frente = nuevo;
    }else{
        this->final->next = nuevo;
        this->final = this->final->next;
    }
}

NodoPedido * ColaPedidos::desencolar(){
    NodoPedido * desencolado = frente;
    if (!this->estaVacia()){
        this->frente = this->frente->next;
        desencolado->next = NULL;
    }
    return desencolado;
}

bool ColaPedidos::estaVacia(){
    if (this->frente == NULL){
        return  true;
    }
    return false;
}

int ColaPedidos::cantidadEnCola(){
    NodoPedido * tmp = frente;
    int contador = 0;
    while (tmp != NULL) {
        contador++;
        tmp = tmp->next;
    }
    return  contador;
}
