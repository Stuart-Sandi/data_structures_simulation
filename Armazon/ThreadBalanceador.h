#ifndef THREADBALANCEADOR_H
#define THREADBALANCEADOR_H
#include <QThread>
#include <ColaPedidos.h>
#include <ColaArticulos.h>
#include <ListaPedidos.h>
#include <ListaArticulos.h>
#include <QMutex>
#include <QDebug>
#include <QList>
#include <pedido.h>
#include <funcionesArchivos.h>


class ThreadBalanceador : public QThread
{
    Q_OBJECT
public:
    int cantidadDesencolado;
    bool pausa;
    ColaPedidos * colaPedidos;
    ColaPedidos * colaPedidosPrioridad;
    ColaPedidos * colaAlisto;
    QList <ColaArticulos*> colasArticulos;
    ListaPedidos * listaPedidos;
    ListaArticulos * articulos;
    QMutex * mutexColaPedidos;
    QMutex * mutex1;//GUARDA EL MUTEX QUE DESENCOLA EN LA COLA DE PEDIDOS
    QMutex * mutex2;//GUARDA EL MUTEX QUE TRABAJARA CON LAS FABRICAS
    ThreadBalanceador(ColaPedidos*,ColaPedidos*,ColaPedidos*,ListaPedidos*,ListaArticulos*,QList<ColaArticulos*>,QMutex*,QMutex*);
    void run() override;

signals:
    void datosCola(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA PEDIDOS//VENTANA COLA PEDIDOS

    void datosBalanceador1(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN BALANCEADOR
    void datosBalanceador2(QString, QString);//ASIGNA LOS DATOS DE CANTIDAD EN BALANCEADOR Y CANTIDAD FINALIZADOS

    void datosColaA(QString);
    void datosColaB(QString);
    void datosColaC(QString);
    void datosColaAB(QString);


};

#endif // THREADBALANCEADOR_H
