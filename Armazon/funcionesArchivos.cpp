#include "funcionesArchivos.h"
#include <QTextStream>
#include <QFile>

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

    }
    archivo.close();

}

void funcionesArchivos::moverArchivo(QString pDireccionAntigua, QString pDireccionNueva){

    QFile::rename(pDireccionAntigua, pDireccionNueva);

}
