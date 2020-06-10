#include "funcionesArchivos.h"

QStringList funcionesArchivos::obtenerListaDeArchivos(QString pCarpeta){

    QString absolute = QFileInfo("../Armazon").absoluteDir().absolutePath() + "/Armazon/" + pCarpeta;
    QStringList lista = QDir(absolute).entryList();
    return lista;
}
