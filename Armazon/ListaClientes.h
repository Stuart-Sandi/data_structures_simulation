#ifndef LISTASIMPLECLIENTES_H
#define LISTASIMPLECLIENTES_H
#include <Cliente.h>
#include <QDebug>

struct ListaClientes{
    Cliente * primerNodo, * ultimoNodo;
    ListaClientes(){
        this->primerNodo = this->ultimoNodo = NULL;
    }
    //DECLARACION DE FUNCIONES
    int insertarCliente(Cliente*);
    int buscarCliente(QString);
    void imprimir();
};


#endif // LISTASIMPLECLIENTES_H
