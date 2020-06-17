#include "Simulacion.h"

int Simulacion::cargarListas(){
/*
 * ES LA FUNCION ENCARGADA DE CARGAR LAS LISTAS DE CLIENTES Y ARTICULOS ANTES DE INICIAR EL PROGRAMA
 * SI RETORNA UN 1 NO ABRIRA LA SIMULACION DEBIDO A ERRORES EN EL ARCHIVO DE CLIENTES
 * SI RETORNA UN 2 NO ABRIRA LA SIMULACION DEBIDO A ERRORES EN EL ARCHIVO DE ARTICULOS
 * SI RETORNA UN 0 PERMITIRA INICIAR LA SIMULACION
 */

//#######################################################################################################
{
/*
 * CARGA LA LISTA DE CLIENTES
 */
    qDebug()<<fA->obtenerFechaHoraActual(true);
    QString name = "";//GUARDA EL NOMBRE DEL ARCHIVO CLIENTES
    QList <QString> words;//GUARDA LAS PALABRAS DE CADA LINEA DE TEXTO

    //OBTIENE LA DIRECCION DE LA CARPETA DE CLIENTES

    QStringList lista = fA->obtenerListaDeArchivos("Clientes");
    QString absolute = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Clientes";

    name = lista[2];//GUARDA EL NOMBRE DEL TXT CON LOS CLIENTES

    QFile datoCliente(QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Clientes/" + name);

    if (!datoCliente.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"No se pudo leer";
        return 1;
    }

    QTextStream in(&datoCliente);
    //VARIABLES TEMPORALES QUE ALMACENAN LOS DATOS DEL CLIENTE DE CADA LINEA
    QString tmpCodigo = "";
    QString tmpNombre = "";
    int tmpPrioridad = 0;

    while (!in.atEnd()) {
         QString line = in.readLine();//LEE EL ARCHIVO POR LINEAS
         words = line.split("\t");//SEPARA LOS DATOS POR TABULADORES

         if (words.size() == 3){
             //ASIGNA LOS DATOS A LAS VARIABLES TMPS QUE SERAN USADAS PARA CREAR EL CLIENTE
             tmpCodigo = words[0];
             tmpNombre = words[1];
             tmpPrioridad = words[2].toInt();

             //VALIDA SI LOS DATOS DE CODIGO Y PRIORIDAD ESTEN CORRECTOS
             //NOTA(AL UTILIZAR LA FUNCION .TOINT SI EL DATO NO SE LOGRA CONVERTIR SE LE ASIGNA 0 POR ESO VALIDO
             //QUE EL TMPCODIGO SEA MAYOR QUE 0)
             if (tmpPrioridad >0 && tmpPrioridad<=10 && words[0].toInt() > 0 && tmpNombre != ""){
                 int validar = 0;
                 Cliente * nuevo = new Cliente(tmpCodigo,tmpNombre,tmpPrioridad);

                 //VALIDA SI EL CLIENTE YA EXISTE EN MEMORIA
                 validar = this->clientes->insertarCliente(nuevo);
                 if (validar == 0){
                     qDebug()<<"ERROR: EL CLIENTE YA EXISTE";
                     return 1;
                 }
                 qDebug()<<"Se inserto el cliente: "+tmpNombre+"\n";
             }else{
                 qDebug()<<"ERROR AL TRANSFORMAR A ENTERO";
                 return 1;
             }
         }
         else{
             return 1;
         }



    }
    datoCliente.close();
}

//#######################################################################################################
{
/*
 * CARGA LA LISTA DE ARTICULOS
 */
    QString name = "";//GUARDA EL NOMBRE DEL ARCHIVO ARTICULOS
    QList <QString> words;//GUARDA LAS PALABRAS DE CADA LINEA DE TEXTO

    //OBTIENE LA DIRECCION DE LA CARPETA DE ARTICULOS

    QStringList lista = fA->obtenerListaDeArchivos("Articulos");

    name = lista[2];//GUARDA EL NOMBRE DEL TXT CON LOS ARTICULOS

    QFile datoArticulo(QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Articulos/" + name);
    if (!datoArticulo.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"No se pudo leer";
        return 2;
    }

    QTextStream in(&datoArticulo);

    //VARIABLES TEMPORALES QUE ALMACENAN LOS DATOS DEL ARTICULO DE CADA LINEA
    QString tmpCodigo = "";
    int tmpCantidad = 0;
    int tmpTiempo = 0;
    QString tmpCategoria = "";
    QString tmpUbicacion = "";

    while (!in.atEnd()) {
         QString line = in.readLine();//LEE EL ARCHIVO POR LINEAS
         words = line.split("\t");//SEPARA LOS DATOS POR TABULADORES

         //ASIGNA LOS DATOS A LAS VARIABLES TMPS QUE SERAN USADAS PARA CREAR EL CLIENTE

         tmpCodigo = words[0];
         tmpCantidad = words[1].toInt();
         tmpTiempo = words[2].toInt();
         tmpCategoria = words[3];
         tmpUbicacion = words[4];
         qDebug()<<"Codigo: "+words[0]+" Cantidad: "+words[1]+" Tiempo: "+words[2]+" Categoria: "+words[3]+" Ubicacion: "+words[4];
         QList<QString> letrasArticulo = {"A", "B", "C", "a", "b", "c"}; //CATEOGRIAS DE LOS ARTICULOS

         //VALIDA SI LOS DATOS DEl TXT ESTAN COMPLETOS Y CORRECTOS
         if (tmpTiempo >0 && tmpCantidad >= 0 && letrasArticulo.contains(words[3]) && tmpCodigo != "" && tmpUbicacion != ""){
             int validar = 0;
             Articulo * nuevo = new Articulo(tmpCodigo,tmpCantidad,tmpTiempo,tmpCategoria,tmpUbicacion);

             //VALIDA SI EL ARTICULO YA EXISTE EN MEMORIA
             validar = this->articulos->insertarArticulo(nuevo);
             if (validar == 0){
                 qDebug()<<"ERROR: EL ARTICULO YA EXISTE";
                 return 2;
             }
         }else{
             return 2;
         }

    }
    datoArticulo.close();

}
    return 0; // SI TODO ESTA CORRECTO
}

void Simulacion::iniciarSimulacion(){
/*
 * ESTA ES LA FUNCION ENCARGADA DE INICIAR TODOS LOS HILOS DE LA SIMULACION
 */
    this->tColaPedidos->start();
    this->tBalanceador->start();
    this->tFabricaA->start();
    this->tFabricaB->start();
    this->tFabricaC->start();
    this->tFabricaComodin->start();
    this->tColaAlisto->start();
    //HILOS DE LOS ALISTADORES
    this->tAlistador1->start();
    this->tAlistador2->start();
    this->tAlistador3->start();
    this->tAlistador4->start();
    this->tAlistador5->start();
    this->tAlistador6->start();
    this->tBodega->start();
    this->tEmpacador->start();
    this->tRobot->start();
}

void Simulacion::detenerSimulacion(){
    this->tColaPedidos->quit();
    this->tBalanceador->quit();
    this->tFabricaA->quit();
    this->tFabricaB->quit();
    this->tFabricaC->quit();
    this->tFabricaComodin->quit();
    this->tColaAlisto->quit();
    //HILOS DE LOS ALISTADORES
    this->tAlistador1->quit();
    this->tAlistador2->quit();
    this->tAlistador3->quit();
    this->tAlistador4->quit();
    this->tAlistador5->quit();
    this->tAlistador6->quit();
    this->tBodega->quit();
    this->tEmpacador->quit();
    this->tRobot->quit();
}
