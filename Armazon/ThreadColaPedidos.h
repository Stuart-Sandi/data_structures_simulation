#ifndef THREADCOLAPEDIDOS_H
#define THREADCOLAPEDIDOS_H
#include <QtCore>
#include <ColaPedidos.h>
#include <pedido.h>
#include <ListaClientes.h>
#include <ListaArticulos.h>

class ThreadColaPedidos : public QThread
{
    Q_OBJECT
public:
    ColaPedidos * colaPedidos;
    QMutex * mutex;
    ListaClientes * clientes;
    ListaArticulos * articulos;

    //Variables de errores temporales
    QString errorNumPedido = "\nERROR: El numero de pedido es incorrecto.";
    QString errorCliente = "\nERROR: El cliente no se encuentra registrado en ARMAZON.";
    QString errorArticulo = "\nERROR: El articulo no existe en los almacenes de ARMAZON.";
    QString errorCantArticulo1 = "\nERROR: La cantidad del articulo : ";
    QString errorCantArticulo2 = " es menor o igual a 0. ";


    ThreadColaPedidos(ColaPedidos*,ListaClientes*,ListaArticulos*,QMutex*);
    void run() override;
};

#endif // THREADCOLAPEDIDOS_H
