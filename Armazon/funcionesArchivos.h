#ifndef FUNCIONESARCHIVOS_H
#define FUNCIONESARCHIVOS_H

#include <QFile>
#include <QDir>
#include <QStringList>

struct funcionesArchivos{

    funcionesArchivos(){

    }

    QStringList obtenerListaDeArchivos(QString);
    void escribirArchivo(QString, QString);
    void moverArchivo(QString, QString);
    QString obtenerFechaHoraActual(void);

};

#endif // FUNCIONESARCHIVOS_H
