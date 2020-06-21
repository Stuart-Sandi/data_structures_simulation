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
    ColaPedidos * colaPedidosPrioridad;
    QMutex * mutex;
    ListaClientes * clientes;
    ListaArticulos * articulos;
    QStringList * listaCodigosPedidos;
    funcionesArchivos * fA;

    //Variables de errores temporales
    QString errorNoInformacion = "\nERROR: El archivo txt esta carente de información.";
    QString errorNumPedido = "\nERROR: El número de pedido es incorrecto.";
    QString errorNumPedido2 = "\nERROR: El número de pedido se encuentra repetido.";
    QString errorCliente = "\nERROR: El cliente no se encuentra registrado en ARMAZON.";
    QString errorArticulo = "\nERROR: La información del articulo está inclompleta.";
    QString errorArticulo1 = "\nERROR: El artículo: ";
    QString errorArticulo2 = " no existe en los almacenes de ARMAZON.";
    QString errorCantArticulo1 = "\nERROR: La cantidad del artículo ";
    QString errorCantArticulo2 = " es menor o igual a 0.";


    ThreadColaPedidos(ColaPedidos*,ColaPedidos*,QStringList *,ListaClientes*,ListaArticulos*,QMutex*);
    void run() override;

signals:
    void datosCola(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA
    void datosCola2(QString, QString);//ASIGNA LOS DATOS DE CANTIDAD EN COLA Y CANTIDAD DESENCOLADOS

};

#endif // THREADCOLAPEDIDOS_H
