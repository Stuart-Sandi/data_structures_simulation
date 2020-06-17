#include "ThreadColaAlisto.h"

ThreadColaAlisto::ThreadColaAlisto(QList<Pedido*> * pPedidos,ColaPedidos *pColaAlisto,QMutex * pMutex1)
{
    this->pausa = false;
    this->pedidos = pPedidos;
    this->colaAlisto = pColaAlisto;
    this->mutex1 = pMutex1;
    this->finalizados = 0;
}

void ThreadColaAlisto::run(){
    bool primeraVez;
    while (true){
        //WHILE QUE PAUSA EL THREAD
        while(this->pausa){
            sleep(1);
        }

        while (true){
            primeraVez = true;
            if(this->mutex1->try_lock()){

                Pedido * tmp = NULL;
                QList <int> pedidosEliminar;

                //RECORRE LA LISTA PARA BUSCAR LOS PEDIDOS COMPLETOS
                for (int w = 0; w<this->pedidos->size(); w++){
                    int validador = 0; // 0 SI TODO ESTA COMPLETO, 1 SI ESTA INCOMPLETO

                    tmp = this->pedidos->at(w);
                    tmp->next = tmp->before = NULL;

                    //VALIDA SI TODOS ESTAN BIEN
                    for (int i = 0; i<tmp->articulos.size(); i++){
                        if (!tmp->articulos[i]->estado){
                            validador = 1;
                        }
                    }

                    //EL PEDIDO ESTA COMPLETO
                    if (validador == 0){


                        for (int i = 0; i<tmp->articulos.size(); i++) {

                            if (tmp->articulos[i]->aFabrica != "") { //AGREGA EL VALOR DE "A FABRICA" AL archivoFacturador

                                if (primeraVez){
                                    tmp->archivoFacturador += "A fabrica:";
                                    tmp->archivoFacturador += "\t\t\t" + tmp->articulos[i]->aFabrica;
                                    primeraVez = false;
                                }else{
                                    tmp->archivoFacturador += "\t\t\t\t" + tmp->articulos[i]->aFabrica;
                                }

                            }
                        }

                        tmp->archivoFacturador += "A alisto:\t" + fA->obtenerFechaHoraActual() + "\n";

                        this->colaAlisto->encolar(tmp);

                        pedidosEliminar.append(w);
                        finalizados++;
                        int cantidadCola = this->colaAlisto->cantidadEnCola();
                        emit datosCola(tmp->numeroPedido+" "+fA->obtenerFechaHoraActual(),QString::number(cantidadCola));
                        break;
                    }
                }

                //ELIMINA LOS FINALIZADOS
                for (int i = 0; i< pedidosEliminar.size(); i++){
                    this->pedidos->removeAt(pedidosEliminar[i]);
                }
                pedidosEliminar.clear();

                emit datosBalanceador(QString::number(this->pedidos->size()),QString::number(this->finalizados));//muestra el proceseo de la cantidad de finalizados del balanceador

                mutex1->unlock();
                break;

            }else{
                msleep(100);
            }
        }

        sleep(1);
    }
}
