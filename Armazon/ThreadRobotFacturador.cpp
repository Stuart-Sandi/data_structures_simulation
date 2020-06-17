#include "ThreadRobotFacturador.h"

ThreadRobotFacturador::ThreadRobotFacturador(ColaPedidos * pColaPedidos, QMutex * pMutex4, QStringList * pListaCodigosPedidos){

    this->colaEmpacados = pColaPedidos;
    this->listaCodigosPedidos = pListaCodigosPedidos;
    this->mutex4 = pMutex4;
    this->finalizados = 0;
    this->pausa = false;

}

void ThreadRobotFacturador::run(){

    funcionesArchivos * fA = new funcionesArchivos();
    QString ARTICULO;
    QString facturacionFinal;
    QString nombreArchivo;
    bool primeraVez;

    while (true) {

        ARTICULO = "";
        facturacionFinal = "";
        nombreArchivo = "";
        primeraVez = true;

        //WHILE DE LA PAUSA
        while (this->pausa){
            sleep(1);
        }

        Pedido * tmp = NULL;
        QString datos = "";
        emit datosCola(QString::number(this->colaEmpacados->cantidadEnCola()),QString::number(this->finalizados),"",2);
        while (true) {

            if(this->mutex4->try_lock()){
                tmp = colaEmpacados->desencolar();
                this->mutex4->unlock();
                break;

            } else {
                msleep(100);
            }

        }

        if(tmp != NULL){

            datos += tmp->numeroPedido+"  "+fA->obtenerFechaHoraActual();
            emit datosCola(QString::number(this->colaEmpacados->cantidadEnCola()),QString::number(this->finalizados),datos,0);
            sleep(1);
            this->finalizados++;
            emit datosCola(QString::number(this->colaEmpacados->cantidadEnCola()),QString::number(this->finalizados),datos,1);
            for (int i = 0; i<tmp->articulos.size(); i++) {

                if(tmp->articulos[i]->totalFabrica != ""){

                    if (primeraVez) {
                        ARTICULO += tmp->articulos[i]->totalFabrica;
                        primeraVez = false;
                    } else {

                        ARTICULO += "\t" + tmp->articulos[i]->totalFabrica;

                    }

                }

            }

            facturacionFinal += tmp->archivoFacturador + "Finalizado:\t\t" + fA->obtenerFechaHoraActual() + "\n\n";

            if(ARTICULO != ""){

                facturacionFinal += "Fabrica\n";
                facturacionFinal += "ARTICULO" + ARTICULO + "\n";

            }

            facturacionFinal += "Alisto" + tmp->alisto;

            QString absolutePath = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Facturados/";
            absolutePath += tmp->numeroPedido + "_" + tmp->codigoCliente + "_" + fA->obtenerFechaHoraActual2()+ ".txt";
            fA->escribirArchivo(absolutePath, facturacionFinal);
            this->listaCodigosPedidos->removeAt(this->listaCodigosPedidos->indexOf(tmp->numeroPedido)); //BORRA EL NUMERO DE PEDIDO DE LA LISTA

        }

        sleep(1);

    }
}
