#ifndef ARTICULOALMACEN_H
#define ARTICULOALMACEN_H

#include <QString>

struct ArticuloAlmacen{

    QString codigo;
    int cantidad;
    int segundosFabricacion;
    QString categoria;
    QString ubicacionBodega;

    ArticuloAlmacen(QString pCodigo, int pCantidad, int pSegundosFabricacion, QString pCatagoria, QString pUbicacionBodega){

        this->codigo = pCodigo;
        this->cantidad = pCantidad;
        this->segundosFabricacion = pSegundosFabricacion;
        this->categoria = pCatagoria;
        this->ubicacionBodega = pUbicacionBodega;

    }

};

#endif // ARTICULOALMACEN_H
