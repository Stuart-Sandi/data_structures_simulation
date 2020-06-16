#ifndef FUNCIONESARCHIVOS_H
#define FUNCIONESARCHIVOS_H

#include <QFile>
#include <QDir>
#include <QList>
#include <QStringList>
#include <QDebug>

struct funcionesArchivos{
    QList <QString> palabrasMayu;
    QList <QString> palabrasMinu;
    funcionesArchivos(){
        palabrasMayu = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        palabrasMinu = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    }

    QStringList obtenerListaDeArchivos(QString);
    void escribirArchivo(QString, QString);
    void moverArchivo(QString, QString);
    QString obtenerFechaHoraActual(void);
    int translatorLetras(QString);

};

#endif // FUNCIONESARCHIVOS_H
