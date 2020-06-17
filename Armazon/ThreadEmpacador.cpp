#include "ThreadEmpacador.h"

ThreadEmpacador::ThreadEmpacador(ColaPedidos * pColaAlistados, ColaPedidos * pColaFacturacion, QMutex * pMutex3, QMutex * pMutex4){

    this->colaAlistados = pColaAlistados;
    this->colaFacturacion = pColaFacturacion;
    this->contador = 0;
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
        QString dato = "";

        //WHILE ENCARGADO DE PAUSAR EL THREAD DEPENDIENDO
        while (this->pausa) {
            sleep(1);
        }
        emit datosCola(QString::number(this->colaAlistados->cantidadEnCola()), QString::number(this->contador), "", 2);
        while (true) {

            if(this->mutex3->try_lock()){

                tmp = colaAlistados->desencolar();

                if(tmp != NULL){
                    cantidadArticulos = tmp->articulos.size();
                    dato += tmp->numeroPedido+"\nTiempo: "+QString::number(cantidadArticulos)+" segundos\n"+fA->obtenerFechaHoraActual();
                    emit datosCola(QString::number(this->colaAlistados->cantidadEnCola()), QString::number(this->contador), dato, 0);
                }

                mutex3->unlock();
                break;

            } else {

                msleep(100);

            }
        }
        if (tmp != NULL){
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
                        this->contador++;
                        dato = "";
                        dato += tmp->numeroPedido+" "+fA->obtenerFechaHoraActual();
                        emit datosCola(QString::number(this->colaAlistados->cantidadEnCola()), QString::number(this->contador), dato, 1);
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
