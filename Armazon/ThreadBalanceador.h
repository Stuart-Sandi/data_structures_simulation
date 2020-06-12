#ifndef THREADBALANCEADOR_H
#define THREADBALANCEADOR_H
#include <QThread>
#include <ColaPedidos.h>
#include <QMutex>
#include <QDebug>
#include <pedido.h>


class ThreadBalanceador : public QThread
{
    Q_OBJECT
public:
    int cantidadDesencolado;
    bool pausa;
    ColaPedidos * colaPedidos;
    ColaPedidos * colaPedidosPrioridad;
    QMutex * mutexColaPedidos;
    QMutex * mutex1;//GUARDA EL MUTEX QUE DESENCOLA EN LA COLA DE PEDIDOS
    QMutex * mutex2;//GUARDA EL MUTEX QUE TRABAJARA CON LAS FABRICAS
    ThreadBalanceador(ColaPedidos*,ColaPedidos*,QMutex*,QMutex*);
    void run() override;

signals:
    void datosCola(QString,QString);

};

#endif // THREADBALANCEADOR_H
