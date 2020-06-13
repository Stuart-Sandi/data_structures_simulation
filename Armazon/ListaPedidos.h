#ifndef LISTAPEDIDOS_H
#define LISTAPEDIDOS_H
#include <pedido.h>
#include <QDebug>

struct ListaPedidos{
    Pedido * primerNodo, *ultimoNodo;
    ListaPedidos(){
        this->primerNodo = this->ultimoNodo = NULL;
    }
    void insertarCliente(Pedido*);
    Pedido * sacarCliente(QString);
    int cantidadEnLista();
    void imprimir();
};

#endif // LISTAPEDIDOS_H
