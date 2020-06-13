#include "ThreadBalanceador.h"

ThreadBalanceador::ThreadBalanceador(ColaPedidos * pColaNormal,ColaPedidos * pColaPrioridad,ColaPedidos * pColaAlisto,ListaPedidos * pPedidos,ListaArticulos * pArticulos,QList<ColaArticulos*> pColasArticulos, QMutex* pMutex1, QMutex* pMutex2)
{
    this->cantidadDesencolado = 0;
    this->pausa = false;
    this->colaPedidos = pColaNormal;
    this->colaPedidosPrioridad = pColaPrioridad;
    this->colaAlisto = pColaAlisto;
    this->colasArticulos = pColasArticulos;
    this->listaPedidos = pPedidos;
    this->articulos = pArticulos;
    this->mutex1 = pMutex1;
    this->mutex2 = pMutex2;
}

void ThreadBalanceador::run(){

    while (true){

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa){
            sleep(1);
        }

        Pedido * tmp = NULL;
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
                msleep(100);
            }
        }

        //VALIDA SI EL PEDIDO SE DESENCOLO
        if (tmp != NULL){
            while (true) {
                if (this->mutex2->try_lock()){
                    //RECORRE TODOS LOS ARTICULOS DEL PEDIDO
                    for (int i = 0; i<tmp->articulos.size();i++){
                        int cantidadArticulo = tmp->articulos[i]->cantidad;
                        int cantidadAlmacen = this->articulos->buscarArticulo(tmp->articulos[i]->codigo)->cantidad;
                        qDebug()<<"Cantidad almacen: "<<cantidadAlmacen;
                        qDebug()<<"Cantidad requerida: "<<cantidadArticulo<<endl;

                        //PREGUNTA SI LA CANTIDAD DEL ALAMACEN ES MAYOR O IGUAL QUE LA CANTIDAD NECESITADA
                        if (cantidadAlmacen >= cantidadArticulo){
                            tmp->articulos[i]->estado = true;
                            this->articulos->buscarArticulo(tmp->articulos[i]->codigo)->cantidad -= cantidadArticulo;
                        }else{
                            //INGRESA EN LA COLA A
                            if (tmp->articulos[i]->categoria == "A" || tmp->articulos[i]->categoria == "a"){
                                this->colasArticulos[0]->encolar(tmp->articulos[i]);
                            }
                            //INGRESA EN LA COLA B
                            else if (tmp->articulos[i]->categoria == "B" || tmp->articulos[i]->categoria == "b"){
                                this->colasArticulos[1]->encolar(tmp->articulos[i]);
                            }
                            //INGRESA EN LA COLA C
                            else{
                                this->colasArticulos[2]->encolar(tmp->articulos[i]);
                            }
                        }
                    }
                    //INSERTA EN LA LISTA DE LOS PEDIDOS
                    this->listaPedidos->insertarCliente(tmp);
                    this->listaPedidos->cantidadEnLista();
                    this->mutex2->unlock();
                    break;
                }else{
                    msleep(100);
                }

            }

        }

        sleep(1);
    }
}
