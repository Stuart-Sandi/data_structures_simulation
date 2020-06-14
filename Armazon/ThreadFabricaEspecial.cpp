#include "ThreadFabricaEspecial.h"

ThreadFabricaEspecial::ThreadFabricaEspecial(ColaArticulos * pColaArticulosA, ColaArticulos * pColaArticulosB, ListaArticulos * pListaArticulos, QMutex * pMutex1)
{
    this->colaArticulosA = pColaArticulosA;
    this->colaArticulosB = pColaArticulosB;
    this->articulos = pListaArticulos;
    this->categoria = "AB";
    this->mutex1 = pMutex1;
    this->pausa = false;

}

void ThreadFabricaEspecial::run()
{
    while (true) {

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa) {
            sleep(1);
        }

        Articulo * tmp = NULL;
        int cantidadFaltante;

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

                    /*SE MULTIPLICA LA CANTIDAD A CREAR POR EL TIEMPO DE CREACIÓN PARA HALLAR EL TIEMPO QUE DURARÁN HACIÉNDOSE LOS PEDIDOS*/
                    this->tiempo = cantidadFaltante * tmp->tiempoCreacion;

                    //RESTA EN EL ALMACÉN
                    this->articulos->buscarArticulo(tmp->codigo)->cantidad = 0;
                }

                mutex1->unlock();
                break;

            } else {

                msleep(100);

            }
        }


        if (tmp != NULL){

            //CREANDO ARTÍCULO
            sleep(this->tiempo);

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
    }
}
