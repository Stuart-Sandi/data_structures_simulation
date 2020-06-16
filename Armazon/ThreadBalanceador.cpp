#include "ThreadBalanceador.h"

ThreadBalanceador::ThreadBalanceador(ColaPedidos * pColaNormal,ColaPedidos * pColaPrioridad,ColaPedidos * pColaAlisto,QList<Pedido*> * pPedidos,ListaArticulos * pArticulos,QList<ColaArticulos*> pColasArticulos, QMutex* pMutex1, QMutex* pMutex2)
{
    this->cantidadDesencolado = 0;
    this->pausa = false;
    this->colaPedidos = pColaNormal;
    this->colaPedidosPrioridad = pColaPrioridad;
    this->colaAlisto = pColaAlisto;//NO LA UTILIZA PARA NADA
    this->colasArticulos = pColasArticulos;
    this->pedidos = pPedidos;
    this->articulos = pArticulos;
    this->mutex1 = pMutex1;
    this->mutex2 = pMutex2;
}

void ThreadBalanceador::run(){

    funcionesArchivos * fA = new funcionesArchivos();

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
                    tmp->archivoFacturador += "Balanceador: " + fA->obtenerFechaHoraActual() + "\n";
                    int cantA = this->colaPedidos->cantidadEnCola()+this->colaPedidosPrioridad->cantidadEnCola();
                    this->cantidadDesencolado++;
                    emit datosCola(QString::number(cantA),QString::number(this->cantidadDesencolado));

                //PREGUNTA SI LA COLA NORMAL NO ESTA VACIA
                }else if (this->colaPedidos->cantidadEnCola() != 0){
                    tmp = this->colaPedidos->desencolar();
                    tmp->archivoFacturador += "Balanceador: " + fA->obtenerFechaHoraActual() + "\n";
                    int cantA = this->colaPedidos->cantidadEnCola()+this->colaPedidosPrioridad->cantidadEnCola();
                    this->cantidadDesencolado++;
                    emit datosCola(QString::number(cantA),QString::number(this->cantidadDesencolado));

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

                        //PREGUNTA SI LA CANTIDAD DEL ALAMACEN ES MAYOR O IGUAL QUE LA CANTIDAD NECESITADA
                        if (cantidadAlmacen >= cantidadArticulo){
                            this->articulos->buscarArticulo(tmp->articulos[i]->codigo)->cantidad -= cantidadArticulo;
                            tmp->articulos[i]->estado = true;
                        }else{
                            //INGRESA EN LA COLA A

                            //Convierte la cantidad para que vaya bien a la cola
                            tmp->articulos[i]->cantidad -= this->articulos->buscarArticulo(tmp->articulos[i]->codigo)->cantidad;
                            this->articulos->buscarArticulo(tmp->articulos[i]->codigo)->cantidad = 0;

                            if (tmp->articulos[i]->categoria == "A" || tmp->articulos[i]->categoria == "a"){
                                this->colasArticulos[0]->encolar(tmp->articulos[i]);
                                emit datosColaA(QString::number(this->colasArticulos[0]->cantidadEnCola()));
                                emit datosColaAB(QString::number(this->colasArticulos[0]->cantidadEnCola()+this->colasArticulos[1]->cantidadEnCola()));
                            }
                            //INGRESA EN LA COLA B
                            else if (tmp->articulos[i]->categoria == "B" || tmp->articulos[i]->categoria == "b"){
                                this->colasArticulos[1]->encolar(tmp->articulos[i]);
                                emit datosColaB(QString::number(this->colasArticulos[1]->cantidadEnCola()));
                                emit datosColaAB(QString::number(this->colasArticulos[0]->cantidadEnCola()+this->colasArticulos[1]->cantidadEnCola()));
                            }
                            //INGRESA EN LA COLA C
                            else{
                                this->colasArticulos[2]->encolar(tmp->articulos[i]);
                                emit datosColaC(QString::number(this->colasArticulos[2]->cantidadEnCola()));
                            }
                        }
                    }
                    //INSERTA EN LA LISTA DE LOS PEDIDOS
                    this->pedidos->append(tmp);
                    emit datosBalanceador1(tmp->numeroPedido+ "  " + fA->obtenerFechaHoraActual(), QString::number(this->pedidos->size()));
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
