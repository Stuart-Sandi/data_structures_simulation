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
