#ifndef PEDIDO_H
#define PEDIDO_H

#include <QString>
#include "articulo.h"

struct Pedido
{

    QString numeroPedido;
    QString codigoCliente;
    Articulo * articulo;
    QString archivoFacturador;

    Pedido(QString pNumeroPedido, QString pCodigoCliente, Articulo *pArticulo){

        this->numeroPedido = pNumeroPedido;
        this->codigoCliente = pCodigoCliente;
        this->articulo = pArticulo;
        this->archivoFacturador = "Pedido:" + this->numeroPedido + "\n" + "Cliente: " + this->codigoCliente +"\n";


    }

};

#endif // PEDIDO_H
