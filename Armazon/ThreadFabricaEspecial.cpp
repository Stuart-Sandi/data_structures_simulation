#include "ThreadFabricaEspecial.h"

ThreadFabricaEspecial::ThreadFabricaEspecial(ColaArticulos * pColaArticulosA, ColaArticulos * pColaArticulosB, ListaArticulos * pListaArticulos, QMutex * pMutex1)
{
    this->colaArticulosA = pColaArticulosA;
    this->colaArticulosB = pColaArticulosB;
    this->articulos = pListaArticulos;
    this->categoria = "Comodin";
    this->contador = 0;
    this->mutex1 = pMutex1;
    this->pausa = false;

}

void ThreadFabricaEspecial::run()
{
    funcionesArchivos * fA = new funcionesArchivos();
    QString datoVentana;

    while (true) {

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa) {
            sleep(1);
        }

        Articulo * tmp = NULL;
        int cantidadFaltante;
        int tiempoDeCreacion;
        QString fechaHorainicio = "";

        while (true) {
            if(this->mutex1->try_lock()){

                //IF ANIDADO QUE DECIDE CUÁL COLA AYUDAR SEGÚN QUÉ TAN LLENAS ESTÉN
                if(colaArticulosA->cantidadEnCola() >= 5 && colaArticulosB->cantidadEnCola() >= 5){

                    if(colaArticulosA->cantidadEnCola() >= colaArticulosB->cantidadEnCola()){

                        tmp = colaArticulosA->desencolar();

                    } else if (colaArticulosB->cantidadEnCola() >= colaArticulosA->cantidadEnCola()){

                        tmp = colaArticulosB->desencolar();
                    }

                } else if(colaArticulosA->cantidadEnCola() >= 5){

                    tmp = colaArticulosA->desencolar();

                } else if(colaArticulosB->cantidadEnCola() >= 5){

                    tmp = colaArticulosB->desencolar();

                }

                if(tmp != NULL){ //Si desencola
                    //Obtiene los artículos que faltan por fabricar
                    cantidadFaltante = tmp->cantidad - articulos->buscarArticulo(tmp->codigo)->cantidad;
                    tiempoDeCreacion = articulos->buscarArticulo(tmp->codigo)->tiempoCreacion;

                    fechaHorainicio = fA->obtenerFechaHoraActual();
                    tmp->aFabrica += "\t\t\t" + fechaHorainicio + " Faltaba " + QString::number(cantidadFaltante) + " de " + tmp->codigo;

                    /*SE MULTIPLICA LA CANTIDAD A CREAR POR EL TIEMPO DE CREACIÓN PARA HALLAR EL TIEMPO QUE DURARÁN HACIÉNDOSE LOS PEDIDOS*/
                    this->tiempo = cantidadFaltante * tiempoDeCreacion;

                    //RESTA EN EL ALMACÉN
                    this->articulos->buscarArticulo(tmp->codigo)->cantidad = 0;
                }

                mutex1->unlock();
                break;

            } else {

                msleep(100);

            }
        }

        emit datosCola(QString::number(this->colaArticulosA->cantidadEnCola()+this->colaArticulosB->cantidadEnCola()),QString::number(this->contador));
        if (tmp != NULL){

            //CREANDO ARTÍCULO
            datoVentana = QString::number(cantidadFaltante)+" unidades del "+tmp->codigo+" del pedido #"+tmp->numeroPedido+"  "+fA->obtenerFechaHoraActual();
            emit asignarPreparando(datoVentana,0);
            sleep(this->tiempo);
            datoVentana = QString::number(cantidadFaltante)+" unidades del "+tmp->codigo+" del pedido #"+tmp->numeroPedido+"  "+fA->obtenerFechaHoraActual()+"\n";
            emit asignarPreparando(datoVentana,1);
            tmp->totalFabrica += tmp->codigo + "\t" + "Fabricado en " + this->categoria + "\n" + QString::number(cantidadFaltante) + " unidades"
                    + "\n" + "inicio:\t" + fechaHorainicio + "\n" + "final:\t" + fA->obtenerFechaHoraActual();

            this->contador++;

            while (true) {

                if(this->mutex1->try_lock()){

                    tmp->estado = true;
                    mutex1->unlock();
                    break;

                } else {

                    msleep(100);

                }
            }
        }
        sleep(1);
    }
}
