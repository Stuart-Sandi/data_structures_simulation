#include "ThreadColaPedidos.h"

ThreadColaPedidos::ThreadColaPedidos(ColaPedidos * pColaPedidos,ListaClientes * pClientes,ListaArticulos * pArticulos ,QMutex * pMutex)
{
    this->colaPedidos = pColaPedidos;
    this->clientes = pClientes;
    this->articulos = pArticulos;
    this->mutex = pMutex;
}

void ThreadColaPedidos::run(){

    while (true) {

        QString name = "";//GUARDA EL NOMBRE DEl TXT
        QList <QString> data;//GUARDA LAS PALABRAS DE CADA LINEA DE TEXTO
        QList <QString> articulo;//GUARDA EL PAR ORDENADO DE LOS ARTICULOS SOLICTADOS


        //OBTIENE LA DIRECCION DE LA CARPETA DE PEDIDOS
        QStringList lista = fA->obtenerListaDeArchivos("Pedidos");

        for (int i = 2; i<lista.size(); i++){
            QString error = "";
            name = lista[i];//GUARDA EL NOMBRE DEL TXT CON LOS CLIENTES
            Pedido * nuevo;//ALMACENA EL NUEVO PEDIDO

            QFile datoPedido(QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Pedidos/" + name);
            if (!datoPedido.open(QIODevice::ReadOnly | QIODevice::Text)){
                qDebug()<<"No se pudo leer";
                return;//validar despues
            }
            QTextStream in(&datoPedido);
            QString text = in.readAll();//LEE EL ARCHIVO POR LINEAS
            data = text.split("\n");//SEPARA LOS DATOS POR TABULADORES

            if (data.size()>2 && data[0] != ""){
                QString numPedido = data[0];
                //VALIDA QUE EL NUMERO DE PEDIDO SEA UN ENTERO
                if (numPedido.toInt()== 0){
                    error += this->errorNumPedido;
                }

                QString codigoCliente = data[1];
                //VALIDA QUE EL CLIENTE EXISTA EN MEMORIA
                if (this->clientes->buscarCliente(codigoCliente) == 0){
                    error += this->errorCliente;
                }
                if (error == ""){
                    nuevo = new Pedido();
                }

                QString codigoProducto = "";
                int cantidadSolicitada = 0;

                //OBTIENE LOS DATOS DE CADA ARTICULO DEL PEDIDO
                for (int i = 2; i<data.size();i++){

                    articulo = data[i].split("\t");

                    //VALIDA QUE CADA ARTICULO ESTE COMPLETO
                    if (articulo.size() > 1){
                        codigoProducto = articulo[0];
                        cantidadSolicitada = articulo[1].toInt();
                        if (this->articulos->buscarArticulo(codigoProducto) == NULL){
                            error += this->errorArticulo1+codigoProducto+this->errorArticulo2;
                        }
                        if (cantidadSolicitada <= 0){
                            error += this->errorCantArticulo1 + codigoProducto + this->errorCantArticulo2;
                        }
                        if (error == ""){
                            Articulo * nuevo2 = new Articulo();
                            Articulo * tmp = this->articulos->buscarArticulo(codigoProducto);
                            nuevo2->codigo = tmp->codigo;
                            nuevo2->cantidad = cantidadSolicitada;
                            nuevo2->categoria = tmp->categoria;
                            nuevo2->ubicacion = tmp->ubicacion;
                            nuevo->articulos.append(nuevo2);
                        }
                    }else{
                        error += this->errorArticulo;
                    }

                }
            }else{
                error += this->errorNoInformacion;
            }
            datoPedido.close();

            if(error != ""){ //SI HAY ERRORES, LOS ESCRIBE EN EL ARCHIVO Y LO MANDA A LA CARPETA ERROR
                QString absolute = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Pedidos/";
                QString absolute2 = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Error/";
                fA->escribirArchivo(absolute+name, error);
                fA->moverArchivo(absolute+name, absolute2+name);
                qDebug()<<"PEDIDO NO ENCOLADO"<<endl;

            }else{//SI NO HAY ERRORES, MUEVE EL ARCHIVO A LA CARPETA COMPLETADOS Y ENCOLA
                QString absolute = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Pedidos/";
                QString absolute2 = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Completados/";
                fA->moverArchivo(absolute+name, absolute2+name);

                //TRATA DE BLOQUEAR EL RECURSO PARA ENCOLAR
                while (true){
                    if (this->mutex->try_lock()){
                        this->colaPedidos->encolar(nuevo);
                        this->mutex->unlock();
                        qDebug()<<"PEDIDO ENCOLADO"<<endl;
                        break;
                    }else{
                        qDebug()<<"No obtuvo el recurso"<<endl;
                        msleep(100);
                    }
                }
            }

        }

        sleep(1);

    }

}
