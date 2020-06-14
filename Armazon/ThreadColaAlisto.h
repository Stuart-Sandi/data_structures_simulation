#ifndef THREADCOLAALISTO_H
#define THREADCOLAALISTO_H
#include <QtCore>
#include <ListaPedidos.h>
#include <ColaPedidos.h>
#include <QMutex>


class ThreadColaAlisto : public QThread
{
    Q_OBJECT
public:
    bool pausa;
    ListaPedidos * pedidos;
    ColaPedidos * colaAlisto;
    QMutex * mutex1,* mutex2;
    ThreadColaAlisto(ListaPedidos*,ColaPedidos*,QMutex*,QMutex*);
    void run() override;

signals:

};

#endif // THREADCOLAALISTO_H
