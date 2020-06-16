#ifndef THREADBODEGA_H
#define THREADBODEGA_H
#include <QtCore>
#include <QList>
#include <QQueue>
#include <QMutex>
#include <ColaPedidos.h>
#include <ThreadAlistador.h>


class ThreadBodega :   public QThread
{
    Q_OBJECT
public:
    bool pausa;
    QMutex * mutex;
    int desencolados;
    ColaPedidos * colaAlisto;
    QList <ThreadAlistador*> listaAlistadores;
    QQueue <ThreadAlistador*> colaAlistadores;
    ThreadBodega(ColaPedidos*,QList<ThreadAlistador*>,QQueue<ThreadAlistador*>,QMutex*);
    void run() override;

signals:
    void datosAlisto(QString,QString);//Actualiza los desencolados y encolados de la ventana alisto
    void datosBodega(QString,QString,QString);

};

#endif // THREADBODEGA_H
