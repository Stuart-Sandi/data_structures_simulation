#ifndef THREADCOLAALISTO_H
#define THREADCOLAALISTO_H
#include <QtCore>
#include <ListaPedidos.h>
#include <ColaPedidos.h>
#include <funcionesArchivos.h>
#include <QMutex>


class ThreadColaAlisto : public QThread
{
    Q_OBJECT
public:
    bool pausa;
    ListaPedidos * pedidos;
    ColaPedidos * colaAlisto;
    QMutex * mutex1,* mutex2;
    funcionesArchivos * fA;
    ThreadColaAlisto(ListaPedidos*,ColaPedidos*,QMutex*,QMutex*);
    void run() override;

signals:
    void datosBalanceador(QString,QString);
    void datosCola(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA
    void datosCola2(QString, QString);//ASIGNA LOS DATOS DE CANTIDAD EN COLA Y CANTIDAD DESENCOLADOS

};

#endif // THREADCOLAALISTO_H
