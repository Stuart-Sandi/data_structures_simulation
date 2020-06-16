#ifndef THREADEMPACADOR_H
#define THREADEMPACADOR_H

#include <QThread>
#include <pedido.h>
#include <ColaPedidos.h>
#include <QMutex>
#include <funcionesArchivos.h>

class ThreadEmpacador : public QThread
{
    Q_OBJECT
public:
    ColaPedidos * colaAlistados;
    ColaPedidos * colaFacturacion;
    QMutex * mutex3;
    QMutex * mutex4;
    bool pausa;


    ThreadEmpacador(ColaPedidos*, ColaPedidos*, QMutex*, QMutex*);
    void run() override;
};

#endif // THREADEMPACADOR_H
