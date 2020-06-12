#include "ListaClientes.h"


int ListaClientes::insertarCliente(Cliente * nuevo){
/*
 * PROCEDIMIENTO ENCARGADO DE INSERTAR UN CLIENTE AL FINAL DE LA LISTA
 */

    //VALIDA SI EXISTE EL CLIENTE YA EN LISTA
    Cliente * validarE = this->buscarCliente(nuevo->codigo);
    if (validarE == NULL){

        //INSERTA AL FINAL DE LA LISTA
        if (this->primerNodo == NULL){
            this->primerNodo = this->ultimoNodo = nuevo;
        }else{
            this->ultimoNodo->next = nuevo;
            this->ultimoNodo = nuevo;
        }
        return 1;

    }else {
        return 0;
    }
}

Cliente * ListaClientes::buscarCliente(QString codigo){
/*
 * PROCEDIMIENTO ENCARGADO DE VERIFICAR LA EXISTENCIA DEL CLIENTE EN LISTA
 */
    Cliente * tmp = this->primerNodo;
    while (tmp != NULL) {
        if (tmp->codigo == codigo){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void ListaClientes::imprimir(){
/*
 * PROCEDIMIENTO ENCARGADO DE IMPRIMIR LA LISTA
 */
    Cliente * tmp = this->primerNodo;
    while (tmp != NULL) {
        qDebug()<<tmp->codigo;
        qDebug()<<tmp->nombre;
        qDebug()<<tmp->prioridad<<endl;
        tmp = tmp->next;
    }
}
