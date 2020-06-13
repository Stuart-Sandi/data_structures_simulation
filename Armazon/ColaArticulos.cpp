#include "ColaArticulos.h"

void ColaArticulos::encolar(Articulo * pDato){
    if (this->estaVacia()){
        this->final = this->frente = pDato;
    }else{
        this->final->next = pDato;
        this->final = this->final->next;
    }
}

Articulo * ColaArticulos::desencolar(){
    Articulo * desencolado = frente;
    if (!this->estaVacia()){
        this->frente = this->frente->next;
        desencolado->next = NULL;
    }
    return desencolado;
}

bool ColaArticulos::estaVacia(){
    if (this->frente == NULL){
        return  true;
    }
    return false;
}

int ColaArticulos::cantidadEnCola(){
    Articulo * tmp = frente;
    int contador = 0;
    while (tmp != NULL) {
        contador++;
        tmp = tmp->next;
    }
    return  contador;
}
