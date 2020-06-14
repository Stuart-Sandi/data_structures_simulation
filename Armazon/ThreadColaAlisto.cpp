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
                        //SOLO DESENCOLA UNO
                        Pedido * pedido = this->pedidos->sacarPedido(tmp->numeroPedido);
                        this->colaAlisto->encolar(pedido);
                        break;
                    }
                    tmp = tmp->next;

                }

                mutex1->unlock();
                break;

            }else{
                msleep(100);
            }
        }

        sleep(1);
    }
}
