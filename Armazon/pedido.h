#ifndef PEDIDO_H
#define PEDIDO_H

#include <QString>
#include "articulo.h"
#include <QList>

struct Pedido
{

    QString numeroPedido;
    QString codigoCliente;
    int prioridad;
    QList <Articulo*> articulos;
    QString archivoFacturador = "";
    QString alisto = "";
    Pedido * next, *before;
    Pedido(){
        this->next = NULL;
        this->before = NULL;
    }

    Pedido(QString pNumeroPedido, QString pCodigoCliente, QList<Articulo*> pArticulos){

        this->numeroPedido = pNumeroPedido;
        this->codigoCliente = pCodigoCliente;
        this->articulos = pArticulos;
        this->next = NULL;
        this->before = NULL;

    }

};

#endif // PEDIDO_H
