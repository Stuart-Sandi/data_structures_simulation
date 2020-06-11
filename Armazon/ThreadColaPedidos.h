#ifndef THREADCOLAPEDIDOS_H
#define THREADCOLAPEDIDOS_H
#include <QtCore>
#include <ColaPedidos.h>
#include <pedido.h>
#include <ListaClientes.h>
#include <ListaArticulos.h>
#include <funcionesArchivos.h>
#include <QDateTime>

class ThreadColaPedidos : public QThread
{
    Q_OBJECT
public:
    ColaPedidos * colaPedidos;
    QMutex * mutex;
    ListaClientes * clientes;
    ListaArticulos * articulos;
    funcionesArchivos * fA;

    //Variables de errores temporales
    QString errorNoInformacion = "\nERROR: El archivo txt esta carente de informacion.";
    QString errorNumPedido = "\nERROR: El numero de pedido es incorrecto.";
    QString errorNumPedido2 = "\nERROR: El numero de pedido es se encuentra repetido.";
    QString errorCliente = "\nERROR: El cliente no se encuentra registrado en ARMAZON.";
    QString errorArticulo = "\nERROR: La informacion del articulo esta inclompleta";
    QString errorArticulo1 = "\nERROR: El articulo: ";
    QString errorArticulo2 = " ,no existe en los almacenes de ARMAZON.";
    QString errorCantArticulo1 = "\nERROR: La cantidad del articulo : ";
    QString errorCantArticulo2 = " es menor o igual a 0. ";


    ThreadColaPedidos(ColaPedidos*,ListaClientes*,ListaArticulos*,QMutex*);
    void run() override;
};

#endif // THREADCOLAPEDIDOS_H
