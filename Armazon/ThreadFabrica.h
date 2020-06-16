#ifndef THREADFABRICA_H
#define THREADFABRICA_H

#include <QThread>
#include <ColaPedidos.h>
#include <ColaArticulos.h>
#include <ListaArticulos.h>
#include <QMutex>
#include <QDebug>
#include <QList>
#include <pedido.h>
#include <funcionesArchivos.h>

class ThreadFabrica : public QThread
{
    Q_OBJECT

public:

    ColaArticulos * colaArticulos;
    ListaArticulos * articulos;
    int tiempo;
    int contador;
    bool pausa;
    QString categoria;
    QMutex * mutex1;

    ThreadFabrica(ColaArticulos*, ListaArticulos*, QString, QMutex*);
    void run() override;

signals:
    void asignarPreparando(QString, int);
    void datosCola(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA PEDIDOS//VENTANA COLA PEDIDOS

};

#endif // THREADFABRICA_H
