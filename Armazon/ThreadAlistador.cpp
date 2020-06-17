#include "ThreadAlistador.h"

ThreadAlistador::ThreadAlistador(QString pNombre,ColaPedidos * pColaAlistados, QMutex * pMutex, QString pNumAlistador)
{
    this->pausa = false;
    this->pedido = NULL;
    this->nombre = pNombre;
    this->numAlistador = pNumAlistador;
    this->totalElaborados = 0;
    this->disponible = 0;
    this->mutex = pMutex;
    this->fA = new funcionesArchivos();
    this->alistados = pColaAlistados;
}

void ThreadAlistador::run(){

    QString alisto = "";
    while(true){

        //WHILE DE LA PAUSA
        while (pausa){
            sleep(1);
        }

        //SI ES VERDADERO COMIENZA EL PROCESO
        if (this->disponible == 1){
            QString letra;
            QString data = "";
            QString nS1;
            QString nS2;
            int numero1 = 0;
            int numero2 = 0;
            int cont = this->pedido->articulos.size();
            emit datosAlistador(QString::number(cont),data,QString::number(this->totalElaborados));

            alisto += "\t\tAlistador " + this->numAlistador + "\n";

            //RECORRE TODOS LOS ARTICULOS DE LA LISTA
            for (int i = 0; i<this->pedido->articulos.size(); i++){
                data = "";

                //OBTIENE EL VALOR DE LA LETRA
                letra = this->pedido->articulos[i]->ubicacion[0];
                numero1 = fA->translatorLetras(letra);

                //OBTIENE EL VALOR DEL NUMERO
                nS1 = this->pedido->articulos[i]->ubicacion[1];
                nS2 = this->pedido->articulos[i]->ubicacion[2];
                letra = nS1+nS2;
                numero2 = letra.toInt();

                numero1 += numero2;
                numero1 *= 2;

                //ESTABLECE EL TIEMPO DE DURACION
                QString codigoA = this->pedido->articulos[i]->codigo;
                QString posicion = this->pedido->articulos[i]->ubicacion;
                data += "El alistador esta buscando el articulo: "+codigoA+"\nUbicacion: "+posicion+"\nTiempo de busqueda: "+QString::number(numero1)+"\n"+fA->obtenerFechaHoraActual();

                alisto += "\t\t" + codigoA + "\t" + "Ubicacion " + posicion + "\t" + QString::number(numero1) + " segundos\n";

                emit datosAlistador(QString::number(cont),data,QString::number(this->totalElaborados));
                for (int w = 0; w< numero1; w++){
                    //PAUSA EN CASO DE QUE SE PAUSE EL ALISTADOR MIENTRAS TRABAJA
                    while (pausa){
                        sleep(1);
                    }
                    sleep(1);
                }
                cont--;
                this->totalElaborados++;
                data = "El alistador alisto el articulo: "+codigoA+"\n"+fA->obtenerFechaHoraActual();
                emit datosAlistador(QString::number(cont),data,QString::number(this->totalElaborados));
            }
            //ENCOLA EL PEDIDO FINALIZADO EN LA COLA DE ALISTADOS
            while (true) {

                if(this->mutex->try_lock()){
                    this->pedido->alisto += alisto;
                    this->alistados->encolar(this->pedido);
                    this->mutex->unlock();
                    break;

                }else{
                    msleep(100);
                }
            }
            this->disponible = 2;
            qDebug()<<"ALISTO EL PEDIDO"<<"CANTIDAD EN COLA: "<<this->alistados->cantidadEnCola();
            //emit

        }

        sleep(1);
    }
}
