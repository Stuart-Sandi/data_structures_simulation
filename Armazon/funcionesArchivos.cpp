#include "funcionesArchivos.h"
#include <QTextStream>
#include <QFile>
#include <QDateTime>

QStringList funcionesArchivos::obtenerListaDeArchivos(QString pCarpeta){

    QString absolute = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/" + pCarpeta;
    QStringList lista = QDir(absolute).entryList();
    return lista;
}

void funcionesArchivos::escribirArchivo(QString pDireccionArchivo, QString pTexto){

    QFile archivo(pDireccionArchivo);
    if(archivo.open(QIODevice::Append | QIODevice::Text)){
        QTextStream datosArchivo(&archivo);
        datosArchivo << pTexto <<endl;

    }else{
        qDebug()<<"NO CREO EL ARCHIVO";
    }
    archivo.close();

}

void funcionesArchivos::escribirArchivoNuevo(QString pDireccionArchivo, QString pTexto){

    QFile archivo(pDireccionArchivo);
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream datosArchivo(&archivo);
        datosArchivo << pTexto <<endl;

    }else{
        qDebug()<<"NO CREO EL ARCHIVO";
    }
    archivo.close();

}

void funcionesArchivos::moverArchivo(QString pDireccionAntigua, QString pDireccionNueva){

    QFile archivo(pDireccionNueva);
    if(!archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QFile::rename(pDireccionAntigua, pDireccionNueva);

    }else{
        archivo.close();
        QFile::remove(pDireccionNueva);
        QFile::rename(pDireccionAntigua, pDireccionNueva);
    }

}

QString funcionesArchivos::obtenerFechaHoraActual(){

    QString fechaHoraExacta = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ap");
    return fechaHoraExacta;

}

QString funcionesArchivos::obtenerFechaHoraActual2(){

    QString fechaHoraExacta = QDateTime::currentDateTime().toString("yyyy-MM-dd  hh-mm-ssap");
    return fechaHoraExacta.replace(".","");

}

int funcionesArchivos::translatorLetras(QString letra){
    int contador = 1;
    for (int i = 0; i<this->palabrasMayu.size(); i++){
        if (letra == this->palabrasMayu[i] || letra == this->palabrasMinu[i]){
            return contador;
        }
        contador++;
    }
    return contador;
}

void funcionesArchivos::sobreEscribirAlmacen(ListaArticulos * pListaArticulos){

    Articulo * tmp = pListaArticulos->primerNodo;
    QString almacen = "";
    while (tmp != NULL) {

        almacen += tmp->codigo + "\t";
        almacen += QString::number(tmp->cantidad) + "\t";
        almacen += QString::number(tmp->tiempoCreacion) + "\t";
        almacen += tmp->categoria + "\t";

        if (tmp->next == NULL) {
            almacen += tmp->ubicacion;
        } else {
            almacen += tmp->ubicacion + "\n";
        }

        tmp = tmp->next;
    }

    QStringList lista = obtenerListaDeArchivos("Articulos");

    QString nombreArchivo = lista[2];

    QString absolute = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/Articulos/" + nombreArchivo;

    qDebug()<<absolute;
    escribirArchivoNuevo(absolute, almacen);

}
