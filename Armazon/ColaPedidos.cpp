#include "ColaPedidos.h"

void ColaPedidos::encolar(Pedido * pDato){
    if (this->estaVacia()){
        this->final = this->frente = pDato;
    }else{
        this->final->next = pDato;
        this->final = this->final->next;
    }
}

Pedido * ColaPedidos::desencolar(){
    Pedido * desencolado = frente;
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
    Pedido * tmp = frente;
    int contador = 0;
    while (tmp != NULL) {
        contador++;
        tmp = tmp->next;
    }
    return  contador;
}
