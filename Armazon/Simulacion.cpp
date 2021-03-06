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
                     return 1;
                 }
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

         if (words.size() == 5){
             tmpCodigo = words[0];
             tmpCantidad = words[1].toInt();
             tmpTiempo = words[2].toInt();
             tmpCategoria = words[3];
             tmpUbicacion = words[4];

             //CUALQUIER VARA ELIMINAR EL IF SIGUIENTE Y ESTAS VARIABLES RARAS
             if (tmpUbicacion.size()==3){
                 QString letra = "";
                 letra = tmpUbicacion[0];
                 QString num1 = "";
                 num1 = tmpUbicacion[1];
                 QString num2 = "";
                 num2 = tmpUbicacion[2];
                 QList <QString>palabrasMayu = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
                 QList <QString>palabrasMinu = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
                 QString numFinal = num1+num2;

                 if ( (palabrasMayu.contains(letra)||palabrasMinu.contains(letra)) && (numFinal.toInt()>0 && numFinal.toInt()<=10)){
                     QList<QString> letrasArticulo = {"A", "B", "C", "a", "b", "c"}; //CATEOGRIAS DE LOS ARTICULOS

                     //VALIDA SI LOS DATOS DEl TXT ESTAN COMPLETOS Y CORRECTOS
                     if (tmpTiempo >0 && tmpCantidad >= 0 && letrasArticulo.contains(words[3]) && tmpCodigo != "" && tmpUbicacion != ""){
                         int validar = 0;
                         Articulo * nuevo = new Articulo(tmpCodigo,tmpCantidad,tmpTiempo,tmpCategoria,tmpUbicacion);

                         //SI EXISTE UN ARTÍCULO DIFERENTE CON LA MISMA UBICACION
                         if(this->articulos->buscarUbicacionArticulo(nuevo->ubicacion)){
                             return 2;
                         }

                         //VALIDA SI EL ARTICULO YA EXISTE EN MEMORIA
                         validar = this->articulos->insertarArticulo(nuevo);
                         if (validar == 0){
                             return 2;
                         }

                     }else{
                         return 2;
                     }
                 }else{
                     return 2;
                 }
             }else{
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
