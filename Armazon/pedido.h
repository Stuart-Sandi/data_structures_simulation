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
    Pedido * next = NULL;
    Pedido(){}

    Pedido(QString pNumeroPedido, QString pCodigoCliente, QList<Articulo*> pArticulos){

        this->numeroPedido = pNumeroPedido;
        this->codigoCliente = pCodigoCliente;
        this->articulos = pArticulos;

    }

};

#endif // PEDIDO_H
