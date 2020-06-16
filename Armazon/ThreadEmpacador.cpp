#include "ThreadEmpacador.h"

ThreadEmpacador::ThreadEmpacador(ColaPedidos * pColaAlistados, ColaPedidos * pColaFacturacion, QMutex * pMutex3, QMutex * pMutex4){

    this->colaAlistados = pColaAlistados;
    this->colaFacturacion = pColaFacturacion;
    this->mutex3 = pMutex3;
    this->mutex4 = pMutex4;
    this->pausa = false;

}

void ThreadEmpacador::run()
{
    funcionesArchivos * fA = new funcionesArchivos();
    int cantidadArticulos = 0;

    while (true) {
        Pedido * tmp = NULL;

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa) {
            sleep(1);
        }

        while (true) {

            if(this->mutex3->try_lock()){

                tmp = colaAlistados->desencolar();

                if(tmp != NULL){
                    cantidadArticulos = tmp->articulos.size();
                }

                mutex3->unlock();
                break;

            } else {

                msleep(100);

            }
        }

        if (tmp != NULL){
            qDebug()<<"Nombre temporal empacado: "<<tmp->numeroPedido;
            for (int w = 0; w< cantidadArticulos; w++){
                //PAUSA EN CASO DE QUE SE PAUSE EL ALISTADOR MIENTRAS TRABAJA
                while (pausa){
                    sleep(1);
                }
                sleep(1);
            }

            while(true){

                if(this->mutex4->try_lock()){

                    if(tmp != NULL){
                        tmp->archivoFacturador += "A empaque:\t" + fA->obtenerFechaHoraActual() + "\n";
                        this->colaFacturacion->encolar(tmp); //ENCOLA EN COLA DE FACTURACION
                        qDebug()<<"Cantidad en la cola de facturacion: "<<this->colaFacturacion->cantidadEnCola();
                    }

                    mutex4->unlock();
                    break;

                } else {

                    msleep(100);

                }

            }

        }

        sleep(1);

    }
}
