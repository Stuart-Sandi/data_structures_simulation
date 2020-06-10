#ifndef FUNCIONESARCHIVOS_H
#define FUNCIONESARCHIVOS_H

#include <QFile>
#include <QDir>
#include <QStringList>

struct funcionesArchivos{

    funcionesArchivos(){

    }

    QStringList obtenerListaDeArchivos(QString);

};

#endif // FUNCIONESARCHIVOS_H
