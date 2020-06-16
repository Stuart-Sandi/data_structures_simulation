#ifndef THREADALISTADOR_H
#define THREADALISTADOR_H
#include <QtCore>
#include <ColaPedidos.h>
#include <QMutex>
#include <QDebug>
#include <funcionesArchivos.h>


class ThreadAlistador : public QThread
{
    Q_OBJECT
public:
    funcionesArchivos * fA;
    bool pausa;
    QString nombre;
    Pedido * pedido;
    int disponible;//0 libre, 1 procesando, 2 procesado
    int totalElaborados;
    QMutex * mutex;
    ColaPedidos * alistados;
    ThreadAlistador(QString,ColaPedidos*,QMutex*);
    void run() override;

signals:
    void datosAlistador(QString,QString,QString);

};

#endif // THREADALISTADOR_H
