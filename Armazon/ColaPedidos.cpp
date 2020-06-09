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
