#ifndef THREADFABRICAESPECIAL_H
#define THREADFABRICAESPECIAL_H

#include <QThread>
#include <ColaPedidos.h>
#include <ColaArticulos.h>
#include <ListaPedidos.h>
#include <ListaArticulos.h>
#include <QMutex>
#include <QDebug>
#include <QList>
#include <pedido.h>

class ThreadFabricaEspecial : public QThread
{
    Q_OBJECT

public:

    ColaArticulos * colaArticulosA;
    ColaArticulos * colaArticulosB;
    ListaArticulos * articulos;
    int tiempo;
    bool pausa;
    QString categoria;
    QMutex * mutex1;

    ThreadFabricaEspecial(ColaArticulos*, ColaArticulos*, ListaArticulos*, QMutex*);
    void run() override;
};

#endif // THREADFABRICAESPECIAL_H
