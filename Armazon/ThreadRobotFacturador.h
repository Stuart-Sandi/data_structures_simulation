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
    int finalizados;
    ColaPedidos * colaEmpacados;
    QStringList * listaCodigosPedidos;
    QMutex * mutex4;
    bool pausa;

    ThreadRobotFacturador(ColaPedidos*, QMutex*, QStringList*);
    void run() override;

signals:
    void datosCola(QString,QString,QString,int);

};

#endif // THREADROBOTFACTURADOR_H
