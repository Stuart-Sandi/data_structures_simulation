#ifndef THREADROBOTFACTURADOR_H
#define THREADROBOTFACTURADOR_H

#include <QThread>
#include <pedido.h>
#include <ColaPedidos.h>
#include <QMutex>
#include <funcionesArchivos.h>

class ThreadRobotFacturador : public QThread
{
    Q_OBJECT
public:

    ColaPedidos * colaEmpacados;
    QMutex * mutex4;
    bool pausa;

    ThreadRobotFacturador(ColaPedidos*, QMutex*);
    void run() override;
};

#endif // THREADROBOTFACTURADOR_H
