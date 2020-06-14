#include "ThreadColaAlisto.h"

ThreadColaAlisto::ThreadColaAlisto(ListaPedidos * pPedidos,ColaPedidos *pColaAlisto,QMutex * pMutex1, QMutex * pMutex2)
{
    this->pausa = false;
    this->pedidos = pPedidos;
    this->colaAlisto = pColaAlisto;
    this->mutex1 = pMutex1;
    this->mutex2 = pMutex2;
}

void ThreadColaAlisto::run(){

    while (true){
        //WHILE QUE PAUSA EL THREAD
        while(this->pausa){
            sleep(1);
        }

        int validador = 0; // 0 SI TODO ESTA COMPLETO, 1 SI ESTA INCOMPLETO

        while (true){

            if(this->mutex1->try_lock()){

                //RECORRE LA LISTA PARA BUSCAR LOS PEDIDOS COMPLETOS
                Pedido * tmp = this->pedidos->primerNodo;
                while (tmp != NULL){

                    //VALIDA SI TODOS ESTAN BIEN
                    for (int i = 0; i<tmp->articulos.size(); i++){
                        if (!tmp->articulos[i]->estado){
                            validador = 1;
                        }
                    }

                    //EL PEDIDO ESTA COMPLETO
                    if (validador == 0){
                        QList <int> w;
                        this->colaAlisto->encolar(this->pedidos->sacarPedido(tmp->numeroPedido));
                        emit datosBalanceador(QString::number(this->pedidos->cantidadEnLista()),QString::number(this->colaAlisto->cantidadEnCola()));//muestra el proceseo de la cantidad de finalizados del balanceador
                        qDebug()<<"ENCOLO EN COLA DE ALISTO";
                        qDebug()<<"Tamaño de cola de alisto: "+QString::number(this->colaAlisto->cantidadEnCola());
                        break;
                    }
                    tmp = tmp->next;

                }

                mutex1->unlock();
                break;

            }else{
                qDebug()<<"NO OBTUVO EL RECURSO";
                msleep(100);
            }
        }

        sleep(1);
    }
}
