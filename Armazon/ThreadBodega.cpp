#include "ThreadBodega.h"

ThreadBodega::ThreadBodega(ColaPedidos * pColaAlisto, QList <ThreadAlistador*> pListaAlistadores, QQueue <ThreadAlistador*> pColaAlistadores, QMutex * pMutex)
{
    this->pausa = false;
    this->mutex = pMutex;
    this->desencolados = 0;
    this->colaAlisto = pColaAlisto;
    this->colaAlistadores = pColaAlistadores;
    this->listaAlistadores = pListaAlistadores;
}

void ThreadBodega::run(){

    while (true){

        //PAUSA EL THREAD
        while (this->pausa){
            sleep(1);
        }

        //WHILE ENCARGADO DE DESENCOLAR EL PEDIDO Y EL HILO DEL ALISTADOR
        while (true){
            if (this->mutex->try_lock()){

                //PREGUNTA SI LAS DOS COLAS NO ESTAN VACIAS
                if (this->colaAlisto->cantidadEnCola() != 0 && this->colaAlistadores.size() != 0){

                    ThreadAlistador * tmp = this->colaAlistadores.dequeue(); // Desencolo el alistador
                    tmp->pedido = this->colaAlisto->desencolar();//Agrego el pedido al hilo
                    msleep(200);
                    tmp->disponible = 1;//agrego validacion para empezar a procesar
                    this->desencolados++;
                    emit datosAlisto(QString::number(this->colaAlisto->cantidadEnCola()),QString::number(this->desencolados));

                }
                this->mutex->unlock();
                break;

            }else{
                msleep(100);
            }
        }

        //ESTA VALIDANDO CONSTANTEMENTE SI YA ALGUNO TERMINO SU PROCESO PARA VOLVERLO A ENCOLAR
        int pausados = 0;
        for (int i = 0; i<this->listaAlistadores.size(); i++){
            if (this->listaAlistadores[i]->disponible == 2){
                this->listaAlistadores[i]->disponible = 0;
                this->colaAlistadores.enqueue(this->listaAlistadores[i]);
            }
            if (this->listaAlistadores[i]->pausa){
                pausados++;
            }
        }

        //MUESTRA EL ORDEN DE LOS ALISATDORES
        QString datoCola = "    Orden de Alistadores\n\n";;
        for (int w = 0;w<this->colaAlistadores.size();w++){
            datoCola += this->colaAlistadores.at(w)->nombre;
            datoCola += "\n";
        }
        QString pau = QString::number(pausados);
        QString activos = QString::number(this->listaAlistadores.size()-pausados);
        emit datosBodega(datoCola,activos,pau);

        sleep(1);
    }
}
