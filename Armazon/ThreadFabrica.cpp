#include "ThreadFabrica.h"

ThreadFabrica::ThreadFabrica(ColaArticulos * pColaArticulos, ListaArticulos * pListaArticulos, QString pCategoria, QMutex * pMutex1){

    this->colaArticulos = pColaArticulos;
    this->articulos = pListaArticulos;
    this->contador = 0;
    this->categoria = pCategoria;
    this->tiempo = 0;
    this->mutex1 = pMutex1;
    this->pausa = false;

}

void ThreadFabrica :: run(){

    funcionesArchivos * fA = new funcionesArchivos();
    QString datoVentana = "";

    while(true){

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa) {
            sleep(1);
        }

        Articulo * tmp = NULL;
        int cantidadFaltante = 0;
        int tiempoDeCreacion = 0;
        QString fechaHorainicio = "";
        //WHILE ENCARGADO DE DESENCOLAR
        while(true){

           if(this->mutex1->try_lock()){

               tmp = colaArticulos->desencolar();

               if(tmp != NULL){ //Si desencola

                   //Obtiene los artículos que faltan por fabricar
                   cantidadFaltante = tmp->cantidad;
                   tiempoDeCreacion = articulos->buscarArticulo(tmp->codigo)->tiempoCreacion;

                   fechaHorainicio = fA->obtenerFechaHoraActual();
                   tmp->aFabrica += "\t\t\t" + fechaHorainicio + " Faltaba " + QString::number(cantidadFaltante) + " de " + tmp->codigo;

                   /*SE OBTIENE LA CANTIDAD DE ARTÍCULOS FALTANTE EN EL PEDIDO Y SE MULTIPLICA POR EL TIEMPO DE CREACIÓN
                   PARA HALLAR EL TIEMPO QUE DURARÁN HACIÉNDOSE LOS PEDIDOS*/
                   this->tiempo = cantidadFaltante * tiempoDeCreacion;

                   //RESTA EN EL ALMACÉN
                   //this->articulos->buscarArticulo(tmp->codigo)->cantidad = 0;
               }
               mutex1->unlock();
               break;

           } else {

               msleep(100);

           }
        }

        if (tmp != NULL){

            //CREANDO ARTÍCULO
            datoVentana = QString::number(cantidadFaltante)+" unidades del "+tmp->codigo+" del pedido #"+tmp->numeroPedido+"  Tiempo: "+QString::number(tiempo)+" segundos\n"+fA->obtenerFechaHoraActual();
            emit asignarPreparando(datoVentana,0);
            sleep(this->tiempo);
            datoVentana = QString::number(cantidadFaltante)+" unidades del "+tmp->codigo+" del pedido #"+tmp->numeroPedido+"\n"+fA->obtenerFechaHoraActual()+"\n";
            emit asignarPreparando(datoVentana,1);
            tmp->totalFabrica += tmp->codigo + "\t" + "Fabricado en " + this->categoria + "\n" + QString::number(cantidadFaltante) + " unidades"
                    + "\n" + "inicio:\t" + fechaHorainicio + "\n" + "final:\t" + fA->obtenerFechaHoraActual() + "\n";
            this->contador++;
            emit datosCola(QString::number(this->colaArticulos->cantidadEnCola()),QString::number(this->contador));

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
        sleep(1);
    }
}
