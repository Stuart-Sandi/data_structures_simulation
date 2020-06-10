#ifndef PEDIDO_H
#define PEDIDO_H

#include <QString>
#include "articulo.h"
#include <QList>

struct Pedido
{

    QString numeroPedido;
    QString codigoCliente;
    QList <Articulo*> articulos;
    QString archivoFacturador;

    Pedido(){}

    Pedido(QString pNumeroPedido, QString pCodigoCliente, QList<Articulo*> pArticulos){

        this->numeroPedido = pNumeroPedido;
        this->codigoCliente = pCodigoCliente;
        this->articulos = pArticulos;
        this->archivoFacturador = "Pedido:" + this->numeroPedido + "\n" + "Cliente: " + this->codigoCliente +"\n";


    }

};

#endif // PEDIDO_H
