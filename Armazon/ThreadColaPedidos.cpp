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
        QString error = "";


        //OBTIENE LA DIRECCION DE LA CARPETA DE CLIENTES
        QDir d = QFileInfo("../Armazon").absoluteDir();
        QString absolute=d.absolutePath() + "/Armazon/Pedidos";
        QStringList lista = QDir(absolute).entryList();


        for (int i = 2; i<lista.size(); i++){
            name = lista[i];//GUARDA EL NOMBRE DEL TXT CON LOS CLIENTES
            QFile datoPedido(d.absolutePath() + "/Armazon/Pedidos/" + name);
            if (!datoPedido.open(QIODevice::ReadOnly | QIODevice::Text)){
                qDebug()<<"No se pudo leer";
                return;//validar despues
            }
            QTextStream in(&datoPedido);
            QString text = in.readAll();//LEE EL ARCHIVO POR LINEAS
            data = text.split("\n");//SEPARA LOS DATOS POR TABULADORES

            QString numPedido = data[0];
            //VALIDA QUE EL NUMERO DE PEDIDO SEA UN ENTERO
            if (numPedido.toInt()!= 0){
                error += this->errorNumPedido;
            }

            QString codigoCliente = data[1];
            //VALIDA QUE EL CLIENTE EXISTA EN MEMORIA
            if (this->clientes->buscarCliente(codigoCliente) == 0){
                error += this->errorCliente;
            }
            Pedido * nuevo;
            if (error == ""){
                nuevo = new Pedido();
            }

            QString codigoProducto = "";
            int cantidadSolicitada = 0;

            //OBTIENE LOS DATOS DE CADA ARTICULO DEL PEDIDO
            for (int i = 2; i<data.size();i++){
                articulo = data[i].split("\t");
                codigoProducto = articulo[0];
                cantidadSolicitada = articulo[1].toInt();
                if (this->articulos->buscarArticulo(codigoProducto) == NULL){
                    error += this->errorArticulo;
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

            }

        }

    }

}
