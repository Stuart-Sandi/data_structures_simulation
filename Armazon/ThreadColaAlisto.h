#ifndef THREADCOLAALISTO_H
#define THREADCOLAALISTO_H
#include <QtCore>
#include <QList>
#include <ColaPedidos.h>
#include <funcionesArchivos.h>
#include <QMutex>


class ThreadColaAlisto : public QThread
{
    Q_OBJECT
public:
    bool pausa;
    QList <Pedido*> * pedidos;
    ColaPedidos * colaAlisto;
    int finalizados;
    QMutex * mutex1;
    funcionesArchivos * fA;
    ThreadColaAlisto(QList <Pedido*>*,ColaPedidos*,QMutex*);
    void run() override;

signals:
    void datosBalanceador(QString,QString);
    void datosCola(QString,QString);//ASIGNA LOS DATOS DE PEDIDOS ATENDIDOS Y CANTIDAD EN COLA
    void datosCola2(QString, QString);//ASIGNA LOS DATOS DE CANTIDAD EN COLA Y CANTIDAD DESENCOLADOS

};

#endif // THREADCOLAALISTO_H
