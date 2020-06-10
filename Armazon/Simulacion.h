#ifndef SIMULACION_H
#define SIMULACION_H
#include <QDir>
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
#include <QList>
#include <QMutex>
#include <QDateTime>

#include <ListaClientes.h>
#include <ListaArticulos.h>
#include <ColaPedidos.h>
#include <funcionesArchivos.h>
#include <ThreadColaPedidos.h>


struct Simulacion{

    ListaClientes * clientes;
    ListaArticulos * articulos;
    ColaPedidos * colaPedidos;
    funcionesArchivos * fA;
    ThreadColaPedidos * tColaPedidos;

    QMutex mutex1;

    Simulacion(){
        this->clientes = new ListaClientes();
        this->articulos = new ListaArticulos();
        this->colaPedidos = new ColaPedidos();
        this->fA = new funcionesArchivos();

        this->tColaPedidos = new ThreadColaPedidos(this->colaPedidos,this->clientes,this->articulos, &mutex1);
    }
    int cargarListas();
};

#endif // SIMULACION_H
