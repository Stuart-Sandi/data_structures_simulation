#ifndef THREADFABRICA_H
#define THREADFABRICA_H

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

class ThreadFabrica : public QThread
{
    Q_OBJECT

public:

    ColaArticulos * colaArticulos;
    ListaArticulos * articulos;
    int tiempo;
    bool pausa;
    QString categoria;
    QMutex * mutex1;

    ThreadFabrica(ColaArticulos*, ListaArticulos*, QString,QMutex*);
    void run() override;
};

#endif // THREADFABRICA_H
