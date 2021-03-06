#include "ListaArticulos.h"

int ListaArticulos::insertarArticulo(Articulo * nuevo){
/*
 * PROCEDIMIENTO ENCARGADO DE INSERTAR UN ARTICULO AL FINAL DE LA LISTA
 */

    //VALIDA SI EXISTE EL ARTICULO YA EN LISTA
    if (this->buscarArticulo(nuevo->codigo) == NULL){

        //INSERTA AL FINAL DE LA LISTA
        if (this->primerNodo == NULL){
            this->primerNodo = this->ultimoNodo = nuevo;
        }else{
            this->ultimoNodo->next = nuevo;
            nuevo->before = this->ultimoNodo;
            this->ultimoNodo = nuevo;
        }
        return 1;

    }else {
        return 0;
    }
}


void ListaArticulos::imprimir(){
/*
 * PROCEDIMIENTO ENCARGADO DE IMPRIMIR LA LISTA
 */
    Articulo * tmp = this->primerNodo;
    while (tmp != NULL) {
        qDebug()<<tmp->codigo;
        qDebug()<<tmp->cantidad;
        qDebug()<<tmp->tiempoCreacion;
        qDebug()<<tmp->categoria;
        qDebug()<<tmp->ubicacion<<endl;
        tmp = tmp->next;
    }
}

Articulo * ListaArticulos::buscarArticulo(QString codigo){
/*
 * PROCEDIMIENTO ENCARGADO DE VERIFICAR LA EXISTENCIA DEL ARTICULO EN LISTA
 */
    Articulo * tmp = this->primerNodo;
    while (tmp != NULL) {
        if (tmp->codigo == codigo){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

bool ListaArticulos::buscarUbicacionArticulo(QString pUbicacion){
/*
 * PROCEDIMIENTO ENCARGADO DE VERIFICAR LA EXISTENCIA DE UN ARTÍCULO EN LA MISMA UBICACION
 */
    Articulo * tmp = this->primerNodo;
    while (tmp != NULL) {
        if (tmp->ubicacion == pUbicacion){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
