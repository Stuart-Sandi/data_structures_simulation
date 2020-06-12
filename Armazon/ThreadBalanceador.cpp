#include "ThreadBalanceador.h"

ThreadBalanceador::ThreadBalanceador(ColaPedidos * pColaNormal,ColaPedidos * pColaPrioridad, QMutex* pMutex1, QMutex* pMutex2)
{
    this->cantidadDesencolado = 0;
    this->pausa = false;
    this->colaPedidos = pColaNormal;
    this->colaPedidosPrioridad = pColaPrioridad;
    this->mutex1 = pMutex1;
    this->mutex2 = pMutex2;
}

void ThreadBalanceador::run(){

    while (true){

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa){
            msleep(500);
        }

        Pedido * tmp;
        //WHILE ENCARGADO DE DESENCOLAR
        while (true){
            if (this->mutex1->try_lock()){

                //PREGUNTA SI LA COLA DE PRIORIDAD NO ESTA VACIA
                if (this->colaPedidosPrioridad->cantidadEnCola() != 0){
                    tmp = this->colaPedidosPrioridad->desencolar();
                    int cantA = this->colaPedidos->cantidadEnCola()+this->colaPedidosPrioridad->cantidadEnCola();
                    this->cantidadDesencolado++;
                    emit datosCola(QString::number(cantA),QString::number(this->cantidadDesencolado));
                    qDebug()<<"DESENCOLO EN EL BALANCEADOR";

                //PREGUNTA SI LA COLA NORMAL NO ESTA VACIA
                }else if (this->colaPedidos->cantidadEnCola() != 0){
                    tmp = this->colaPedidos->desencolar();
                    int cantA = this->colaPedidos->cantidadEnCola()+this->colaPedidosPrioridad->cantidadEnCola();
                    this->cantidadDesencolado++;
                    emit datosCola(QString::number(cantA),QString::number(this->cantidadDesencolado));
                    qDebug()<<"DESENCOLO EN EL BALANCEADOR";

                }
                this->mutex1->unlock();
                break;

            }else{
                qDebug()<<"No obtuvo el recurso"<<endl;
                msleep(100);
            }
        }


        sleep(1);
    }
}
