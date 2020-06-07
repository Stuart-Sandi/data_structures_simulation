#ifndef PEDIDO_H
#define PEDIDO_H

#include <QString>
#include "articulo.h"

struct Pedido
{

    QString numeroPedido;
    QString codigoCliente;
    Articulo * articulo;

    Pedido(QString pNumeroPedido, QString pCodigoCliente, Articulo *pArticulo){

        this->numeroPedido = pNumeroPedido;
        this->codigoCliente = pCodigoCliente;
        this->articulo = pArticulo;


    }

};

#endif // PEDIDO_H
