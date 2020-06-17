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
    int contador;
    ColaPedidos * colaAlistados;
    ColaPedidos * colaFacturacion;
    QMutex * mutex3;
    QMutex * mutex4;
    bool pausa;


    ThreadEmpacador(ColaPedidos*, ColaPedidos*, QMutex*, QMutex*);
    void run() override;

signals:
    void datosCola(QString,QString,QString,int);

};

#endif // THREADEMPACADOR_H
