#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>

struct Cliente{
    QString codigo;
    QString nombre;
    int prioridad;
    Cliente(QString pCodigo, QString pNombre, int pPrioridad){
        this->codigo = pCodigo;
        this->nombre = pNombre;
        this->prioridad = pPrioridad;
    }
};


#endif // CLIENTE_H
