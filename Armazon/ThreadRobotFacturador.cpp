#include "ThreadRobotFacturador.h"

ThreadRobotFacturador::ThreadRobotFacturador(ColaPedidos * pColaPedidos, QMutex * pMutex4){

    this->colaEmpacados = pColaPedidos;
    this->mutex4 = pMutex4;
    this->pausa = false;

}

void ThreadRobotFacturador::run(){

    funcionesArchivos * fA = new funcionesArchivos();
    QString ARTICULO = "";
    QString facturacionFinal = "";
    QString nombreArchivo = "";

    while (true) {
        Pedido * tmp = NULL;

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
            qDebug()<<"Nombre tmp en hilo robot: "<<tmp->numeroPedido;
            for (int i = 0; i<tmp->articulos.size(); i++) {

                if(tmp->articulos[i]->totalFabrica != ""){
                    ARTICULO += "\t\t" +tmp->articulos[i]->totalFabrica;
                }

            }

            facturacionFinal += tmp->archivoFacturador + "Finalizado:\t" + fA->obtenerFechaHoraActual() + "\n\n";

            if(ARTICULO != ""){

                facturacionFinal += "Fabrica\n";
                facturacionFinal += "ARTICULO" + ARTICULO;

            }

            facturacionFinal += tmp->alisto;

            QString absolutePath = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Facturados/";
            absolutePath += tmp->numeroPedido + "_" + tmp->codigoCliente +"_"+ fA->obtenerFechaHoraActual()+ ".txt";
            fA->escribirArchivoNuevo(absolutePath, facturacionFinal);

        }

        sleep(1);
    }
}
