#include "ThreadFabrica.h"

ThreadFabrica::ThreadFabrica(ColaArticulos * pColaArticulos, ListaArticulos * pListaArticulos, QString pCategoria, QMutex * pMutex1){

    this->colaArticulos = pColaArticulos;
    this->articulos = pListaArticulos;
    this->categoria = pCategoria;
    this->mutex1 = pMutex1;
    this->pausa = false;

}

void ThreadFabrica :: run(){

    while(true){

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa) {
            sleep(1);
        }

        Articulo * tmp = NULL;
        int cantidadFaltante;
        //WHILE ENCARGADO DE DESENCOLAR
        while(true){

           if(this->mutex1->try_lock()){

               tmp = colaArticulos->desencolar();

               if(tmp != NULL){ //Si desencola
                   //Obtiene los artículos que faltan por fabricar
                   cantidadFaltante = tmp->cantidad - articulos->buscarArticulo(tmp->codigo)->cantidad;

                   /*SE OBTIENE LA CANTIDAD DE ARTÍCULOS FALTANTE EN EL PEDIDO Y SE MULTIPLICA POR EL TIEMPO DE CREACIÓN
                   PARA HALLAR EL TIEMPO QUE DURARÁN HACIÉNDOSE LOS PEDIDOS*/
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

                }else{
                    msleep(100);
                }
            }
        }
    }
}
