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
    QDir d = QFileInfo("../Armazon").absoluteDir();
    QString absolute=d.absolutePath() + "/Armazon/Clientes";
    QStringList lista = QDir(absolute).entryList();

    name = lista[2];//GUARDA EL NOMBRE DEL TXT CON LOS CLIENTES

    QFile datoCliente(d.absolutePath() + "/Armazon/Clientes/" + name);
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

         //ASIGNA LOS DATOS A LAS VARIABLES TMPS QUE SERAN USADAS PARA CREAR EL CLIENTE
         tmpCodigo = words[0];
         tmpNombre = words[1];
         tmpPrioridad = words[2].toInt();

         //VALIDA SI LOS DATOS DE CODIGO Y PRIORIDAD ESTEN CORRECTOS
         //NOTA(AL UTILIZAR LA FUNCION .TOINT SI EL DATO NO SE LOGRA CONVERTIR SE LE ASIGNA 0 POR ESO VALIDO
         //QUE EL TMPCODIGO SEA MAYOR QUE 0)
         if (tmpPrioridad >0 && tmpPrioridad<=10 && words[0].toInt() > 0){
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
}

//#######################################################################################################
{
/*
 * CARGA LA LISTA DE ARTICULOS
 */
    QString name = "";//GUARDA EL NOMBRE DEL ARCHIVO ARTICULOS
    QList <QString> words;//GUARDA LAS PALABRAS DE CADA LINEA DE TEXTO

    //OBTIENE LA DIRECCION DE LA CARPETA DE ARTICULOS
    QDir d = QFileInfo("../Armazon").absoluteDir();
    QString absolute=d.absolutePath() + "/Armazon/Articulos";
    QStringList lista = QDir(absolute).entryList();

    name = lista[2];//GUARDA EL NOMBRE DEL TXT CON LOS ARTICULOS

    QFile datoArticulo(d.absolutePath() + "/Armazon/Articulos/" + name);
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
         QList<QString> letrasArticulo = {"A", "B", "C", "a", "b", "c"};

         //VALIDA SI LOS DATOS DEl TXT ESTAN COMPLETOS Y CORRECTOS
         if (tmpTiempo >0 && tmpCantidad >= 0 && letrasArticulo.contains(words[3])){
             int validar = 0;
             Articulo * nuevo = new Articulo(tmpCodigo,tmpCantidad,tmpTiempo,tmpCategoria,tmpUbicacion);

             //VALIDA SI EL CLIENTE YA EXISTE EN MEMORIA
             validar = this->articulos->insertarArticulo(nuevo);
             if (validar == 0){
                 qDebug()<<"ERROR: EL ARTICULO YA EXISTE";
                 return 2;
             }
             qDebug()<<"Se inserto el cliente: "+tmpCodigo+"\n";
         }else{
             qDebug()<<"ERROR AL TRANSFORMAR A ENTERO";
             return 2;
         }

    }

}
    return 0; // SI TODO ESTA CORRECTO
}
