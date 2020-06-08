#include "Simulacion.h"

int Simulacion::cargarListas(){
/*
 * ES LA FUNCION ENCARGADA DE CARGAR LAS LISTAS DE CLIENTES Y ARTICULOS ANTES DE INICIAR EL PROGRAMA
 * SI RETORNA UN 1 NO ABRIRA LA SIMULACION DEBIDO A ERROR DE LECTURA O ERROR EN EL ARCHIVO
 * SI RETORNA UN 0 PERMITIRA INICIAR LA SIMULACION
 */


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
                 return 1;
             }
             qDebug()<<"Se inserto el cliente: "+tmpNombre+"\n";
         }else{
             qDebug()<<"ERROR AL TRANSFORMAR A ENTERO";
             return 1;
         }

    }
}




{
/*
 * CARGA LA LISTA DE ARTICULOS
 */

}
    return 0; // SI TODO ESTA CORRECTO
}
