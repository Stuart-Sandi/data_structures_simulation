#ifndef THREADFABRICAESPECIAL_H
#define THREADFABRICAESPECIAL_H

#include <QThread>
#include <ColaPedidos.h>
#include <ColaArticulos.h>
#include <ListaArticulos.h>
#include <QMutex>
#include <QDebug>
#include <QList>
#include <pedido.h>
#include <funcionesArchivos.h>

class ThreadFabricaEspecial : public QThread
{
    Q_OBJECT

public:

    ColaArticulos * colaArticulosA;
    ColaArticulos * colaArticulosB;
    ListaArticulos * articulos;
    int tiempo;
    int contador;
    bool pausa;
    QString categoria;
    QMutex * mutex1;

    ThreadFabricaEspecial(ColaArticulos*, ColaArticulos*, ListaArticulos*, QMutex*);
    void run() override;

signals:
    void asignarPreparando(QString, int);
    void datosCola(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA PEDIDOS//VENTANA COLA PEDIDOS
};

#endif // THREADFABRICAESPECIAL_H
